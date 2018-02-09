/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:23:58 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

#define WIN_W 800
#define WIN_H 800

typedef struct	s_th
{
	int 		from;
	int 		to;
	t_img 		*img;
	t_fractal	f;
}				t_th;

void 		julia(t_th *th)
{
	int x;
	int y;
	int i;

	th->f.cr = -0.7;
	th->f.ci = 0.27015;
	y = th->from - 1;
	while (++y < th->to && (x = -1))
		while (++x < WIN_W)
		{
			th->f.ze = 1.5 * (x - WIN_W / 2) / (0.5 * th->f.zoom * WIN_W) +
				th->f.mx;
			th->f.zm = (y - WIN_H / 2) / (0.5 * th->f.zoom * WIN_H) + th->f.my;
			i = -1;
			while (++i < th->f.mi)
			{
				th->f.re = th->f.ze;
				th->f.im = th->f.zm;
				th->f.ze = th->f.re * th->f.re - th->f.im * th->f.im + th->f.cr;
				th->f.zm = 2 * th->f.re * th->f.im + th->f.ci;
				if ((th->f.ze * th->f.ze + th->f.zm * th->f.zm) > 4)
					break;
			}
			th->img->data[y * th->img->height + x] = 919191919 * i;
		}
	pthread_exit(NULL);
}

int			onkeypress(int key, t_win *win)
{
	t_fractal	*f;
	pthread_t	t[16];
	t_th		th[16];

	ft_memset(th, 0, sizeof(t_th) * 16);
	f = win->data;
	if (key == LX_KEYPLUS)
		f->zoom += f->zoom * 0.1;
	else if (key == LX_KEYMINUS)
		f->zoom += f->zoom * -0.1;
	else if (key == LX_KEYLEFT)
		f->mx -= 0.03 / f->zoom;
	else if (key == LX_KEYRIGHT)
		f->mx += 0.03 / f->zoom;
	else if (key == LX_KEYUP)
		f->my -= 0.03 / f->zoom;
	else if (key == LX_KEYDOWN)
		f->my += 0.03 / f->zoom;
	for (int i = 0; i < 16; ++i)
	{
		th[i].img = win->imgs;
		th[i].from = (WIN_H / 16) * i;
		th[i].to = (WIN_H / 16) * (i + 1) + 1;
		th[i].f = *f;
		pthread_create(t + i, NULL, (void *(*)(void *))julia, &th[i]);
	}
	for (int j = 15; j >= 0; --j)
		pthread_join(t[j], NULL);
	lx_winrefresh(win);
	return (YEP);
}

int 		fractol(t_win *win)
{
	static int			init = 0;
	static t_fractal	f;
	t_th				th;

	if (!init)
	{
		init = 1;
		win->data = &f;
		lx_hookexpose(win, (t_event *)fractol);
		lx_hookbtn(win, LX_KEYPRESS, 0, (t_event *)onkeypress);
		return (lx_run());
	}
	ft_memset(&f, 0, sizeof(t_fractal));
	th.img = win->imgs;
	th.from = 0;
	th.to = WIN_H;
	th.f = f;
	julia(&th);
	lx_winrefresh(win);
	return (YEP);
}

int			main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	if (lx_ctor())
		return (EXIT_FAILURE);
	lx_winpush(WIN_W, WIN_H, "fract'ol", (t_event *)fractol);
	lx_dtor();
	return (EXIT_SUCCESS);
}
