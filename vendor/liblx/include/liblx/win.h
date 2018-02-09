/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblx/win.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLX_WIN_H
# define LIBLX_WIN_H

# include "img.h"
# include "mice.h"
# include "event.h"

# define WINIMG_MAX 10

typedef struct	s_win
{
	void		*ptr;
	uint16_t	width;
	uint16_t	height;
	char		*name;
	t_img		imgs[KEYMAP_SZ];
	uint8_t		nimg;
	t_mice		mice;
	void		*data;
}				t_win;

extern int		lx_winpush(uint16_t w, uint16_t h, char *name, t_event *then);
extern void		lx_windtor(void);
extern int		lx_winrefresh(t_win *win);

#endif
