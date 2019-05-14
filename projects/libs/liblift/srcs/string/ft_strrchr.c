/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:24:39 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:32:46 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	while (n + 1)
	{
		if (s[n] == (char)c)
			return (&((char*)s)[n]);
		n--;
	}
	return (NULL);
}