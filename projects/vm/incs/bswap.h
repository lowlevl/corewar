/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:59:22 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/30 19:21:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSWAP_H
# define BSWAP_H

# ifdef __linux__
#  include <byteswap.h>
#  define BSWAP_16 bswap_16
#  define BSWAP_32 bswap_32
#  define BSWAP_64 bswap_64

# elif defined(__OpenBSD__)
#  include <sys/endian.h>
#  define BSWAP_16 __swap16
#  define BSWAP_32 __swap32
#  define BSWAP_64 __swap64

# elif defined(__APPLE__)
#  include <libkern/OSByteOrder.h>
#  define BSWAP_16 OSSwapInt16
#  define BSWAP_32 OSSwapInt32
#  define BSWAP_64 OSSwapInt64

# else
#  include <sys/endian.h>
#  define BSWAP_16 bswap16
#  define BSWAP_32 bswap32
#  define BSWAP_64 bswap64

# endif

#endif
