/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:54:03 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 14:34:01 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argv.h"

void	ft_usage(void)
{
	ft_dprintf(2, DUMP_HELP);
	ft_dprintf(2, N_HELP);
	ft_dprintf(2, HEAT_HELP);
	ft_dprintf(2, SOCKET_HELP);
	ft_dprintf(2, H_HELP);
}
