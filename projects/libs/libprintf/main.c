/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:07:57 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 21:46:42 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>

#define ARGS "%f\n", 1.42f

int	main(void)
{
	int r1, r2;

	r1 = ft_printf(ARGS);
	r2 = printf(ARGS);
	ft_dprintf(2, "---\nReturn values: %d vs %d\n", r1, r2);
}
