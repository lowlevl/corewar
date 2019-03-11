/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/11 15:00:17 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_op.h"
#include <proc.h>

void init_processes(t_vm *vm)
{
	int i;
	size_t start;

	i = 0;
	vm->processes = (t_process*)malloc(0);
	while (i < vm->players_count)
	{
		start = (size_t)((uint8_t*)get_start_in_memory(vm, i) - vm->memory);
		add_processes(vm, start, i);
		i++;
	}
}

// void init_process(t_vm *vm, int player_idx)
// {
// 	vm->processes = (t_process *)malloc(sizeof(t_process));
// 	if_errno_printerr_exit(ERR_PROC_MALL);
// 	vm->processes_count++;
// 	vm->processes->carry = 0;
// 	vm->processes->exec_cycle = -1;
// 	vm->processes->cursor_pos = 0;
// 	vm->processes->cursor_start =
// 		(uint32_t)(get_start_in_memory(vm, player_idx) - (void *)vm->memory);
// 	// print_proc(player->processes); // Debug
// }

void add_processes(t_vm *vm, uint16_t pc, int id)
{
	size_t	 n;
	t_process *proc;

	n = vm->processes_count;
	vm->processes = (t_process *)realloc(vm->processes, sizeof(t_process) * (n + 1));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	vm->processes_count++;
	proc = vm->processes + n;
	ft_printf("%p\n", proc);
	proc->player_id = id;
	proc->cursor_pos = 0;
	proc->carry = 0;
	proc->exec_cycle = 0;
	proc->cursor_start = pc;
}

void exec_cycle(t_vm *vm)
{
	int			i;
	t_process	*process;

	i = 0;
	while (i < vm->processes_count)
	{
		process = vm->processes + i;
		if (vm->cycle_count == process->exec_cycle)
			exec_process(vm, process);
		i++;
	}
	vm->cycle_count++;
}

static const t_op	*get_opcode(uint8_t val) {
	val--;
	if (val >= 0 && val < sizeof(g_op) / sizeof(*g_op)) {
		return g_op + val;
	}
	errno = EINVAL;
	return NULL;
}

void exec_process(t_vm *vm, t_process *process)
{
	uint8_t *pos;
	const t_op	*op;

	pos = get_pos_in_memory(vm->memory, process);
	op = get_opcode(*pos);
	if (!op)
		ft_printf("NOPE\n");
	ft_printf("Exec process %p %#x (%s)\n", pos - vm->memory, op->opcode, op->name);
	if (op->opcode == 0x0b) // sti
		exec_sti(vm, process, op);
}