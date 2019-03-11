/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:59:22 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/11 10:07:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSWAP_H
#define BSWAP_H

# ifdef __linux__
#  include <byteswap.h>
# elif defined(__OpenBSD__)
#  include <sys/endian.h>
#  define bswap_16 __swap16
#  define bswap_32 __swap32
#  define bswap_64 __swap64
# elif defined(__APPLE__)
#  include <libkern/OSByteOrder.h>
#  define bswap_16 OSSwapInt16
#  define bswap_32 OSSwapInt32
#  define bswap_64 OSSwapInt64
# else
#  include <sys/endian.h>
#  define bswap_16 bswap16
#  define bswap_32 bswap32
#  define bswap_64 bswap64
# endif

#endif // !BSWAP_H
