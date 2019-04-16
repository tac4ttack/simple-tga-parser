/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_32bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:48:02 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_32bpp_single(t_tga *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	if (dst == 0)
		fprintf(stdout, "debug -> tga_truecolor_32bpp_single()\n", NULL);
	it = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((it[src + 3] << 24) \
					| (it[src + 2] << 16) \
					| (it[src + 1] << 8) \
					| (it[src]));
}

void 				tga_truecolor_32bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned int	*it;
	fprintf(stdout, "debug -> tga_truecolor_32bpp()\n", NULL);
	i = 0;
	it = (unsigned int *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height)
	{
		pixels[i] = it[i];
		i++;
	}
}
