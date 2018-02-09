/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblx/img.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLX_IMG_H
# define LIBLX_IMG_H

# include <libft.h>

typedef struct	s_img
{
	void		*ptr;
	uint16_t	width;
	uint16_t	height;
	int			*data;
	int			size;
	int			bpp;
	int			endian;
	uint32_t	tick;
}				t_img;

extern int		lx_imgctor(t_img *img, uint16_t width, uint16_t height);
extern void		lx_imgdtor(void);

#endif
