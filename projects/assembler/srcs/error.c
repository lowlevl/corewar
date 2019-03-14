/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:54:48 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 18:42:30 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <lift/io.h>
#include <libpf.h>
#include "main.h"

static const char	*g_err[128] = {
	[1] = "{under}Usage:{eoc} %s <input.s>\n\n"
	"This program compiles only {under}pseudo-asm{eoc} for the project "
	"{bold}corewar{eoc} at school {bold}42{eoc}.\n",
	[2] = NULL,
	[3] = "{bold}%s: {red}error:{eoc} %s\n",
	[4] = "{bold}%s: {red}error:{eoc} Wrong extension. "
	"See usage => {bold}%s{eoc}.\n",
	[5] = "{bold}%s: {red}error:{eoc} No support for infinite/special files "
	"{rev}{shrug}{eoc}.",
	[6] = "{bold}%s: {red}error:{eoc} I/O Error: %s.",
	[7] = "{bold}%s:%d:%d: {red}error:{eoc} Unrecognized instruction {under}%s{eoc}.\n"
	"%s\n"
	"{bold}%*c-- Help:{eoc} You should double check for typo errors."
};

int					perr(int e, ...)
{
	va_list ap;

	va_start(ap, e);
	ft_vdprintf(stderr, g_err[e], ap);
	va_end(ap);
	return (1);
}
