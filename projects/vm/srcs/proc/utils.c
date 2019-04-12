/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:44:25 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/12 15:45:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "socket.h"

size_t count_alive_processes(t_process *node)
{
	size_t count;

	count = 0;
	while (node)
	{
		if (node->have_live != 0)
			count++;
		node = node->next;
	}
	return count;
}

void reset_process_have_live(t_process *node)
{
	while (node)
	{
		node->have_live = 0;
		node = node->next;
	}
}

static void step_forward(t_process **prev, t_process **node)
{
	*prev = *node;
	(*node)->have_live = 0;
	*node = (*node)->next;
}

static void free_node(t_process **node) {
	t_process *tmp;

	tmp = *node;
	*node = (*node)->next;
	free(tmp);
}

void filter_process_have_live(t_vm *vm)
{
	size_t	 nb;
	t_process *node;
	t_process *prev;

	node = vm->processes;
	prev = NULL;
	nb = count_alive_processes(node);
	if (nb == vm->processes_count)
		return reset_process_have_live(node);
	while (node)
	{
		if (node->have_live == 0)
		{
			if (prev)
				prev->next = node->next;
			else
				vm->processes = node->next;
			send_dead_proc(&vm->socket, node);
			free_node(&node);
		}
		else
			step_forward(&prev, &node);
	}
	vm->processes_count = nb;
}
