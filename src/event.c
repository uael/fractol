/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:24:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 15:39:01 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		onclick(int button, int x, int y, t_fl *fl)
{
	(void)x;
	(void)y;
	if (button == 1 || button == 5)
		fl->c.zoom += fl->c.zoom * 0.1;
	if (button == 2 || button == 4)
		fl->c.zoom += fl->c.zoom * -0.1;
	return (draw(fl));
}

int		onkeyrelease(int key, t_fl *fl)
{
	if (key == KEY_ESC)
	{
		mlx_clear_window(fl->mlx, fl->win);
		mlx_destroy_image(fl->mlx, fl->img);
		mlx_destroy_window(fl->mlx, fl->win);
		exit(EXIT_SUCCESS);
	}
	return (YEP);
}

int		onkeypress(int key, t_fl *fl)
{
	if (key == KEY_PLUS || key == KEY_MINUS)
		fl->c.zoom += key == KEY_PLUS ? 0.1 * fl->c.zoom : -0.1 * fl->c.zoom;
	else if (key == KEY_C)
		fl->c.color = fl->c.color < 24772608 ? fl->c.color + 1500 : 189;
	else if (key == KEY_I)
		fl->c.mi += 2;
	else if (key == KEY_D)
		fl->c.mi -= fl->c.mi > 2 ? 2 : 0;
	else if (key == KEY_Q && (fl->c.zoom = 0.5))
		fl->kind = JULIA;
	else if (key == KEY_W && (fl->c.zoom = 0.5))
		fl->kind = MANDELBROT;
	else if (key == KEY_E && (fl->c.zoom = 0.5))
		fl->kind = BURNINGSHIP;
	else if (key == KEY_R && (fl->c.zoom = 0.5))
		fl->kind = TRICORN;
	else if (key == KEY_T && (fl->c.zoom = 0.5))
		fl->kind = FISH;
	key == KEY_UP ? fl->c.my -= 0.03 / fl->c.zoom : 0;
	key == KEY_LEFT ? fl->c.mx -= 0.03 / fl->c.zoom : 0;
	key == KEY_RIGHT ? fl->c.mx += 0.03 / fl->c.zoom : 0;
	key == KEY_DOWN ? fl->c.my += 0.03 / fl->c.zoom : 0;
	return (draw(fl));
}

int		onmotion(int x, int y, t_fl *fl)
{
	if (fl->kind == JULIA)
	{
		if (x > fl->x)
			fl->c.ci += 0.005 / fl->c.zoom;
		if (x < fl->x)
			fl->c.ci -= 0.005 / fl->c.zoom;
		if (y > fl->y)
			fl->c.cr += 0.005 / fl->c.zoom;
		if (y > fl->y)
			fl->c.cr -= 0.005 / fl->c.zoom;
		fl->x = x;
		fl->y = y;
	}
	return (draw(fl));
}

int		onexpose(t_fl *fl)
{
	fl->c.zoom = 0.5;
	fl->c.mi = fl->kind == JULIA ? 125 : 75;
	fl->c.mx = 0;
	fl->c.my = 0;
	fl->c.cr = -0.715;
	fl->c.ci = -0.27015;
	fl->c.color = 189;
	fl->c.fl = fl;
	return (draw(fl));
}
