/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:00:37 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 16:07:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*julia(t_conf *p)
{
	int			x;
	int			i;
	t_fractal	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X)
		{
			v.nr = 1.5 * (x - IMG_X / 2) / (0.5 * p->zoom * IMG_X) + p->mx;
			v.ni = (p->begin - IMG_Y / 2) / (0.5 * p->zoom * IMG_Y) + p->my;
			i = -1;
			while (++i < p->mi && (v.nr * v.nr + v.ni * v.ni) <= 4)
			{
				v.po = v.nr;
				v.pi = v.ni;
				v.nr = v.po * v.po - v.pi * v.pi + p->cr;
				v.ni = 2 * v.po * v.pi + p->ci;
			}
			putpixel(p->fl, x, p->begin, i * p->color);
		}
	pthread_exit(NULL);
}

void		*mandelbrot(t_conf *p)
{
	int			x;
	int			i;
	t_fractal	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X)
		{
			v.rp = 1.5 * (x - WIN_X / 2) / (0.5 * p->zoom * WIN_X) + p->mx;
			v.i = (p->begin - WIN_Y / 2) / (0.5 * p->zoom * WIN_Y) + p->my;
			v.nr = 0;
			v.ni = 0;
			i = -1;
			while (++i < p->mi && (v.nr * v.nr + v.ni * v.ni) <= 4)
			{
				v.po = v.nr;
				v.pi = v.ni;
				v.nr = v.po * v.po - v.pi * v.pi + v.rp;
				v.ni = 2 * v.po * v.pi + v.i;
			}
			putpixel(p->fl, x, p->begin, i * p->color);
		}
	pthread_exit(NULL);
}

void		*burningship(t_conf *p)
{
	int			x;
	int			i;
	t_fractal	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X)
		{
			v.rp = 1.5 * (x - WIN_X / 2) / (0.5 * p->zoom * WIN_X) + p->mx;
			v.i = (p->begin - WIN_Y / 2) / (0.5 * p->zoom * WIN_Y) + p->my;
			v.nr = 0;
			v.ni = 0;
			i = -1;
			while (++i < p->mi && (v.nr * v.nr + v.ni * v.ni) <= 4)
			{
				v.po = v.nr;
				v.pi = v.ni;
				v.nr = ABS(v.po * v.po - v.pi * v.pi + v.rp);
				v.ni = ABS(2 * v.po * v.pi + v.i);
			}
			putpixel(p->fl, x, p->begin, i * p->color);
		}
	pthread_exit(NULL);
}

void		*fish(t_conf *p)
{
	int			x;
	int			i;
	t_fractal	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X)
		{
			v.rp = 1.5 * (x - WIN_X / 2) / (0.5 * p->zoom * WIN_X) + p->mx;
			v.i = (p->begin - WIN_Y / 2) / (0.5 * p->zoom * WIN_Y) + p->my;
			v.nr = 0;
			v.ni = 0;
			i = -1;
			while (++i < p->mi && (v.nr * v.nr + v.ni * v.ni) <= 4)
			{
				v.po = v.nr;
				v.pi = v.ni;
				v.nr = ABS(v.po * v.po - v.pi * v.pi + v.rp);
				v.ni = -2 * v.po * v.pi + v.i;
			}
			putpixel(p->fl, x, p->begin, i * p->color);
		}
	pthread_exit(NULL);
}

void		*tricorn(t_conf *p)
{
	int			x;
	int			i;
	t_fractal	v;

	while (++p->begin < p->end && (x = -1))
		while (++x < IMG_X)
		{
			v.rp = 1.5 * (x - WIN_X / 2) / (0.5 * p->zoom * WIN_X) + p->mx;
			v.i = (p->begin - WIN_Y / 2) / (0.5 * p->zoom * WIN_Y) + p->my;
			v.nr = 0;
			v.ni = 0;
			i = -1;
			while (++i < p->mi && (v.nr * v.nr + v.ni * v.ni) <= 4)
			{
				v.po = v.nr;
				v.pi = v.ni;
				v.nr = v.po * v.po - v.pi * v.pi + v.rp;
				v.ni = -2 * v.po * v.pi + v.i;
			}
			putpixel(p->fl, x, p->begin, i * p->color);
		}
	pthread_exit(NULL);
}
