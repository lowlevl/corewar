/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:54:48 by lroux             #+#    #+#             */
/*   Updated: 2019/04/05 17:07:21 by lroux            ###   ########.fr       */
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
	"{shrug}.\n",
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
	[9] = "{bold}%s:%d:%d: {red}error:{eoc} Unknown instruction '%s':\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Did you mean to write that ?\n",
	[10] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Invalid parameter for instruction '%s':\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Try another parameter type.\n",
	[11] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Too many parameters for instruction '%s':\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Try removing this parameter.\n",
	[12] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Expected token but found a newline instead:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Did you forgot something ?\n",
	[13] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Not enought parameters for instruction '%s':\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Try adding a parameter.\n",
	[14] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Invalid char '%c' in given number:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Maybe try another base ?.\n",
	[15] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Given label is emtpy:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Don't try stupid things {tidy}.\n",
	[16] = "{bold}%s:%d:%d: "
	"{red}error:{eoc} Given number is empty:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Please don't bother me with those errors {flip}.\n",
	[17] = "{bold}%s: {red}error:{eoc} "
	"Given file output is too large {shrug} (at least %dB of %dB max).\n",
	[18] = "{bold}%s:%d:%d: "
	"{magenta}warning:{eoc} Specified command '%s' is unknown:\n"
	"%.*s\n"
	"{bold}%*c-- Help:{eoc} Some requested features may not work.\n",
	[19] = "{bold}%s: "
	"{color;8}linker:{eoc} Undefined reference to symbol '__%s'.\n"
};

int					perr(int e, ...)
{
	va_list ap;

	va_start(ap, e);
	ft_vdprintf(stderr, g_err[e], ap);
	va_end(ap);
	return (1);
}
