/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:54:48 by lroux             #+#    #+#             */
/*   Updated: 2019/03/07 18:38:33 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <lift/io.h>
#include <libpf.h>
#include "error.h"

static const char	*g_err[128] = {
	[0] = "{under}Usage:{eoc} %s <input.s>\n\n"
	"This program compiles only {under}pseudo-asm{eoc} for the project "
	"{bold}corewar{eoc} at school {bold}42{eoc}.\n",
	[1] = "{bold}{shrug}{eoc}: Unknown error.\n",
	[2] = "{bold}%s: {red}error:{eoc} Unknown error at line %d:%d.\n",
	[3] = "{bold}%s: {red}error:{eoc} wrong extension. "
	"See usage => {bold}%s{eoc}.\n",
	[4] = "{bold}%s: {red}error:{eoc} %s\n",
};

int					perr(int e, ...)
{
	va_list ap;

	va_start(ap, e);
	ft_vdprintf(stderr, g_err[e], ap);
	va_end(ap);
	return (1);
}
