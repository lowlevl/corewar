/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:54:48 by lroux             #+#    #+#             */
/*   Updated: 2019/03/25 18:04:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <lift/io.h>
#include <libpf.h>
#include "assembler.h"

static const char	*g_err[128] = {
	[1] = "{under}Usage:{eoc} %s <input.s>\n\n"
	"This program compiles only {under}pseudo-asm{eoc} for the project "
	"{bold}corewar{eoc} at school {bold}42{eoc}.\n",
	[2] = "{bold}%s: {red}error:{eoc} %s\n",
	[3] = "{bold}%s: {red}error:{eoc} Wrong extension. "
	"See usage => {bold}%s{eoc}.\n",
	[4] = "{bold}%s: {red}error:{eoc} No support for infinite/special files "
	"{rev}{shrug}{eoc}.\n",
	[5] = "{bold}%s: {red}error:{eoc} I/O Error: %s.\n",
	[6] = "{bold}%s:%d:%d: {red}error:{eoc} Unexpected token '%s':\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} You should double check for typing errors.\n",
	[7] = "{bold}%s:%d:%d: {red}error:{eoc} Expected closing quote:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} You need to close this quote.\n",
	[8] = "{bold}%s:%d:%d: {red}error:{eoc} Invalid char '%c' in given label:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Check the subject specifications for reference.\n",
/*	[7] = "{bold}%s:%d:%d: {red}error:{eoc} "
	"Unrecognized instruction {under}%s{eoc}.\n"
	"%s\n"
	"{bold}%*c-- Help:{eoc} You should double check for typo errors.\n",
	[8] = "{bold}%s:%d:%d: {red}error:{eoc} "
	"Expected token ('\"'); but found '%c'.\n"
	"%s\n"
	"{bold}%*c-- Help:{eoc} Commands requires opening quotes ('\"') "
	"on param.\n",
	[9] = "{bold}%s:%d:%d: {red}error:{eoc} "
	"Expected token ('\"'); but none found\n"
	"%s\n"
	"{bold}%*c-- Help:{eoc} Commands requires closing quotes ('\"') "
	"on param.\n",
	[10] = "{bold}%s:%d:%d: {red}error:{eoc} "
	"Expected new line ('\\n'); but found '%c' instead\n"
	"%s\n"
	"{bold}%*c-- Help:{eoc} You can't add instructions after commands.\n",
	[11] = "{bold}%s:%d:%d: {red}error:{eoc} Given token '%s' "
	"has no parameter.\n"
*/
};

int					perr(int e, ...)
{
	va_list ap;

	va_start(ap, e);
	ft_vdprintf(stderr, g_err[e], ap);
	va_end(ap);
	return (1);
}
