/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_24bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:27:38 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/15 17:50:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void				tga_colormapped_24bpp(t_tga_info *tga, \
											unsigned int *pix_data)
{
	size_t			i;
	unsigned char	*iterator;
	unsigned char	*cm_ite;
	fprintf(stdout, "debug -> tga_colormapped_24bpp()\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	cm_ite = (unsigned char *)(tga->data + sizeof(t_tga_header) + tga->header->id_len + tga->header->cm_first_entry);
	while (i < (tga->width * tga->height * 3))
	{
		// pix_data[i] = cm_ite[iterator[i * (tga->header->pixel_depth >> 3)]];
		// pix_data[i] = (cm_ite[iterator[i * (tga->header->pixel_depth >> 3)]] & 0xfe << 24)
		// 				| (cm_ite[iterator[i * (tga->header->pixel_depth >> 3)] + 1] & 0xfe << 16)
		// 				| (cm_ite[iterator[i * (tga->header->pixel_depth >> 3)] + 2] & 0xfe << 8)
		// 				| (cm_ite[iterator[i * (tga->header->pixel_depth >> 3)] + 3] & 0xfe);
		// *pix_data = ((0xff << 24) \
		// 			| (cm_ite[iterator[i * tga->header->pixel_depth >> 3] + 2] << 16) \
		// 			| (cm_ite[iterator[i * tga->header->pixel_depth >> 3] + 1] << 8) \
		// 			| (cm_ite[iterator[i * tga->header->pixel_depth >> 3]]));
		i += 3;
		pix_data++;
	}
}
