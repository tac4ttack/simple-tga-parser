/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_32bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/18 10:08:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

bool 				tga_truecolor_32bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (dst == 0)
		POP("tga_truecolor_32bpp_single()");

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((it[src + 3] << 24) \
					| (it[src + 2] << 16) \
					| (it[src + 1] << 8) \
					| (it[src]));
		return (true);
	}
	return (tga_berror("NULL TGA pointer in TC32S!", tga));
}

bool 				tga_truecolor_32bpp(t_tga *tga)
{
	size_t			i;
	unsigned int	*it;

	POP("tga_truecolor_32bpp()");

	i = 0;
	if (tga)
	{
		it = (unsigned int *)(tga->data + tga->data_offset);
		while (i < tga->width * tga->height)
		{
			tga->pixels[i] = it[i];
			i++;
		}
		return (true);
	}
	return (tga_berror("NULL TGA pointer in TC32!", tga));
}
