/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lx.h"

inline int	lx_imgctor(t_img *img, uint16_t width, uint16_t height)
{
	if (!(img->ptr = mlx_new_image(g_lx->ptr, width, height)))
		return (WUT);
	img->width = width;
	img->height = height;
	if (!(img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size,
		&img->endian)))
	{
		mlx_destroy_image(g_lx->ptr, img->ptr);
		return (WUT);
	}
	return (YEP);
}

inline int	lx_hookexpose(t_win *win, t_event *event)
{
	if (!win)
		return (WUT);
	mlx_expose_hook(win->ptr, (int(*)())event, win);
	return (YEP);
}
