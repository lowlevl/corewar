/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _other.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:54:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/10 10:44:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

static const unsigned char base_table[65] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static char *init_out_base(uint8_t *src, size_t len, size_t *out_len)
{
	unsigned char *out;
	size_t		   olen;

	olen = 4 * (len / 3 + 1) + 1;
	if (olen < len || out_len == NULL)
		return NULL;
	out = (char *)malloc(olen * sizeof(unsigned char));
	if (out == NULL)
		return NULL;
	return out;
}

static inline unsigned char *set_pos_value(
	unsigned char *pos, const unsigned char *in)
{
	*pos++ = base_table[in[0] >> 2];
	*pos++ = base_table[((in[0] & 0x3) << 4) | (in[1] >> 4)];
	*pos++ = base_table[((in[1] & 0xf) << 2) | (in[2] >> 6)];
	*pos++ = base_table[in[2] & 0x3f];
	return pos;
}

static inline unsigned char *finish_encoding(
	unsigned char *pos, const unsigned char *in, const unsigned char *end)
{
    if ((end = end - in))
	{
		*pos++ = base_table[in[0] >> 2];
		if (end == 1)
		{
			*pos++ = base_table[(in[0] & 0x3) << 4];
			*pos++ = '=';
		}
		else
		{
			*pos++ = base_table[((in[0] & 0x3) << 4) | (in[1] >> 4)];
			*pos++ = base_table[(in[1] & 0xf) << 2];
		}
		*pos++ = '=';
	}
	*pos = 0;
    return pos;
}

unsigned char *encode_base64(uint8_t *src, size_t len, size_t *out_len)
{
	unsigned char *		 out;
	unsigned char *		 pos;
	const unsigned char *end;
	const unsigned char *in;

	if ((out = init_out_base(src, len, out_len)))
		return NULL;
	end = src + len;
	pos = out;
	in = src;
	while (end - in >= 3)
	{
		pos = set_pos_value(pos, in);
		in += 3;
	}
    pos = finish_encoding(pos, in, end);
	*out_len = out - pos;
	return out;
}
