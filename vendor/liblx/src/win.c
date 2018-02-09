/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lx.h"

inline int		lx_winrefresh(t_win *win)
{
	if (g_lx->ptr == NULL || win == NULL)
		return (-1);
	mlx_clear_window(g_lx->ptr, win->ptr);
	mlx_put_image_to_window(g_lx->ptr, win->ptr, win->imgs[0].ptr, 0, 0);
	mlx_do_sync(g_lx->ptr);
	return (0);
}

static int		keydown(int key)
{
	t_key	*pkey;

	pkey = &g_lx->keymap[key];
	if (pkey->tick - g_lx->tick < 20)
		pkey->status = 3;
	else
		pkey->status = 1;
	pkey->tick = g_lx->tick;
	if (pkey->cb != NULL)
		return (pkey->cb(key, pkey->status, pkey->data));
	return (YEP);
}

static int		keyup(int key)
{
	t_key	*pkey;

	pkey = &g_lx->keymap[key];
	pkey->status = 0;
	if (pkey->cb != NULL)
		return (pkey->cb(key, 0, pkey->data));
	return (YEP);
}

static int		dtor(void)
{
	lx_dtor();
	exit(0);
}

extern int		lx_winpush(uint16_t w, uint16_t h, char *name, t_event *then)
{
	t_win *win;

	win = alloca((g_lx->nwin + 1) * sizeof(t_win));
	if (g_lx->nwin)
		ft_memcpy(win, g_lx->wins, g_lx->nwin * sizeof(t_win));
	g_lx->wins = win;
	win = g_lx->wins + g_lx->nwin++;
	if (!(win->ptr = mlx_new_window(g_lx->ptr, w, h, name)))
		return (WUT);
	if (lx_imgctor(win->imgs, w, h))
	{
		mlx_destroy_window(g_lx->ptr, win->ptr);
		return (WUT);
	}
	win->width = w;
	win->height = h;
	win->name = name;
	mlx_expose_hook(win->ptr, lx_winrefresh, win);
	mlx_hook(win->ptr, 2, (1L << 0), keydown, NULL);
	mlx_hook(win->ptr, 3, (1L << 1), keyup, NULL);
	mlx_hook(win->ptr, 17, 0, dtor, NULL);
	g_lx->focused = win;
	return (then(win));
}
