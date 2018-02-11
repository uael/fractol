/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:36:50 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 15:55:23 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define USAGE "usage: fractol [julia|mandelbrot|burningship|tricorn|fish]\n"

static void	*fractal(uint32_t kind)
{
	if (kind == JULIA)
		return (julia);
	else if (kind == MANDELBROT)
		return (mandelbrot);
	else if (kind == BURNINGSHIP)
		return (burningship);
	else if (kind == TRICORN)
		return (tricorn);
	else if (kind == FISH)
		return (fish);
	return (NULL);
}

int			draw(t_fl *fl)
{
	t_conf		o[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = -1;
	ft_memset(t, 0, sizeof(pthread_t) * THREADS);
	while (++i < THREADS)
	{
		o[i] = fl->c;
		o[i].begin = ((IMG_Y / THREADS) * i) - 1;
		o[i].end = (IMG_Y / THREADS) * (i + 1) + 1;
		pthread_create(t + i, NULL, fractal(fl->kind), o + i);
	}
	while (i--)
		pthread_join(t[i], NULL);
	return (mlxsync(fl->mlx, fl->win, fl->img));
}

void		putpixel(t_fl *fl, int x, int y, int color)
{
	if (y >= IMG_Y || x >= IMG_X || x < 0 || y < 0)
		return ;
	*(int *)&fl->line[(y * fl->size) + (x * (fl->bpp / 8))] = color;
}

int			mlxsync(void *mlx, void *win, void *img)
{
	mlx_clear_window(mlx, win);
	mlx_string_put(mlx, win, IMG_X + 10, 20, 0x0FFFFFF, "Q : Julia");
	mlx_string_put(mlx, win, IMG_X + 10, 40, 0x0FFFFFF, "W : Mandelbrot");
	mlx_string_put(mlx, win, IMG_X + 10, 60, 0x0FFFFFF, "E : Burningship");
	mlx_string_put(mlx, win, IMG_X + 10, 80, 0x0FFFFFF, "R : Tricorn");
	mlx_string_put(mlx, win, IMG_X + 10, 100, 0x0FFFFFF, "T : Fish");
	mlx_string_put(mlx, win, IMG_X + 10, 120, 0x0FFFFFF, "+ / - : Zoom");
	mlx_string_put(mlx, win, IMG_X + 10, 180, 0x0FFFFFF, "UP : Move up");
	mlx_string_put(mlx, win, IMG_X + 10, 200, 0x0FFFFFF, "Down : Move down");
	mlx_string_put(mlx, win, IMG_X + 10, 140, 0x0FFFFFF, "Left : Move Left");
	mlx_string_put(mlx, win, IMG_X + 10, 160, 0x0FFFFFF, "Right: Move Right");
	mlx_string_put(mlx, win, IMG_X + 10, 220, 0x0FFFFFF, "I : Increase precis");
	mlx_string_put(mlx, win, IMG_X + 10, 240, 0x0FFFFFF, "D : Decrease precis");
	mlx_string_put(mlx, win, IMG_X + 10, 260, 0x0FFFFFF, "C : Change color");
	return (mlx_put_image_to_window(mlx, win, img, 0, 0));
}

int			main(int argc, char **argv)
{
	t_fl	fl;

	if (argc != 2)
		return (ft_retf(EXIT_FAILURE, "%e\n"USAGE, EINVAL));
	ft_memset(&fl, 0, sizeof(t_fl));
	fl.kind = ft_strhash(argv[1]);
	if (fl.kind != JULIA && fl.kind != MANDELBROT && fl.kind != FISH &&
		fl.kind != BURNINGSHIP && fl.kind != TRICORN)
		return (ft_retf(EXIT_FAILURE, "unknown fractal\n"USAGE, argv[1]));
	if (!(fl.mlx = mlx_init()) ||
		!(fl.win = mlx_new_window(fl.mlx, WIN_X, WIN_Y, argv[0])) ||
		!(fl.img = mlx_new_image(fl.mlx, IMG_X, IMG_Y)) ||
		!(fl.line = mlx_get_data_addr(fl.img, &fl.bpp, &fl.size,
			&fl.endian)))
		return (ft_retf(EXIT_FAILURE, "error while init mlx\n"));
	mlx_hook(fl.win, KEYRELEASE, KEYRELEASEMASK, onkeyrelease, &fl);
	mlx_hook(fl.win, KEYPRESS, KEYPRESSMASK, onkeypress, &fl);
	mlx_hook(fl.win, MOTIONNOTIFY, POINTERMOTIONMASK, onmotion, &fl);
	mlx_mouse_hook(fl.win, onclick, &fl);
	mlx_expose_hook(fl.win, onexpose, &fl);
	mlx_loop(fl.mlx);
	return (0);
}
