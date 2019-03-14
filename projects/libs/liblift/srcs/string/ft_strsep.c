/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:04:20 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 18:07:38 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*start;
	int		i;

	if (!stringp || !*stringp || !**stringp)
		return (NULL);
	start = *stringp;
	while (**stringp)
	{
		i = -1;
		while (delim[++i])
		{
			if (delim[i] == **stringp)
			{
				**stringp = '\0';
				(*stringp)++;
				return (start);
			}
		}
		(*stringp)++;
	}
	*stringp = NULL;
	return (start);
}
