/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2019/03/02 15:28:45 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/math.h"
#include "lift/types.h"
#include "lift/string.h"

char	*ft_itostr(long long num, int base)
{
	char	*fresh;
	int		index;
	t_bool	invert;

	invert = (num < 0) ? true : false;
	index = ft_intlen(num, base) - 1;
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (1)
	{
		fresh[index--] = BASE36[(invert) ? -(num % base) : (num % base)];
		num = num / base;
		if (!num || index < 0)
			break ;
	}
	if (invert)
		fresh[0] = '-';
	return (fresh);
}
