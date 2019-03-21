/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:45 by lroux             #+#    #+#             */
/*   Updated: 2019/03/16 15:33:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_CHAR_H
# define LIFT_CHAR_H

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `char`:
**   - Char tests.
**   - Char modifiers.
*/

# define SPACE_CHARS "\t\n\v\f\r "

int	ft_inset(int c, const char *charset);

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_isupper(int c);
int	ft_islower(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
