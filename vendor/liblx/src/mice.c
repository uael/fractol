/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lx.h"

static inline int	motion(int x, int y, void *p)
{
	t_mice	*m;

	m = (t_mice*)p;
	if (x < 0 || y < 0 || x >= g_lx->focused->width ||
		y >= g_lx->focused->height)
		return (YEP);
	m->pos = ft_v2(x, y);
	if (m->cb != NULL)
		return (m->cb(m->pos, m->click, m->data));
	return (YEP);
}

inline int			lx_hookmv(t_win *win, t_micecb *cb, void *data)
{
	if (!win)
	{
		errno = EINVAL;
		return (WUT);
	}
	win->mice.pos = ft_v2(0, 0);
	win->mice.click = ft_v2(0, 0);
	win->mice.cb = cb;
	win->mice.data = data;
	mlx_hook(win->ptr, 6, LX_POINTERMOTIONMASK, motion, (void *)&win->mice);
	return (YEP);
}

inline int			lx_hookbtn(t_win *win, int event, int mask, t_event *cb)
{
	if (!win || event < 0 || event >= KEYMAP_SZ)
	{
		errno = EINVAL;
		return (WUT);
	}
	mlx_hook(win->ptr, event, mask, (int(*)())cb, (void*)win);
	return (YEP);
}
