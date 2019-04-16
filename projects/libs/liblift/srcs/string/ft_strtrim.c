/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:29:45 by lroux             #+#    #+#             */
/*   Updated: 2019/03/11 18:30:21 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/string.h"

char	*ft_strtrim(const char *s, int (*check)(int))
{
	char *end;

	if (!s)
		return (NULL);
	while (check(*s))
		++s;
	if (!*s)
		return ((char*)s);
	end = (char*)(s + ft_strlen(s) - 1);
	while (check(*end))
		end--;
	end[1] = '\0';
	return ((char*)s);
}
