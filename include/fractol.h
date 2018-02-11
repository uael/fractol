/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:22:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 16:22:41 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <pthread.h>

# define WIN_X 1250
# define WIN_Y 600
# define IMG_X 1000
# define IMG_Y 600
# define THREADS 16

# define JULIA 101485913
# define MANDELBROT 811421222
# define BURNINGSHIP 3260844143
# define TRICORN 3234964435
# define FISH 3143256

# define KEYPRESS 2
# define KEYRELEASE 3
# define MOTIONNOTIFY 6
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define POINTERMOTIONMASK (1L<<6)

# define KEY_D 2
# define KEY_C 8
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_I 34
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53

struct s_fl;

typedef struct	s_fractal
{
	double		nr;
	double		pi;
	double		po;
	double		ni;
	double		rp;
	double		i;
}				t_fractal;

typedef struct	s_conf
{
	double		cr;
	double		ci;
	double		zoom;
	double		mx;
	double		my;
	int			color;
	int			mi;
	int			begin;
	int			end;
	struct s_fl	*fl;
}				t_conf;

typedef struct	s_fl
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*line;
	int			bpp;
	int			endian;
	int			size;
	uint32_t	kind;
	int			x;
	int			y;
	t_conf		c;
}				t_fl;

void			*julia(t_conf *p);
void			*mandelbrot(t_conf *p);
void			*burningship(t_conf *p);
void			*tricorn(t_conf *p);
void			*fish(t_conf *p);

int				onkeyrelease(int key, t_fl *fl);
int				onkeypress(int key, t_fl *fl);
int				onmotion(int x, int y, t_fl *fl);
int				onexpose(t_fl *fl);
int				onclick(int button, int x, int y, t_fl *fl);

int				draw(t_fl *fl);
int				mlxsync(void *mlx, void *win, void *img);
void			putpixel(t_fl *app, int x, int y, int color);

#endif
