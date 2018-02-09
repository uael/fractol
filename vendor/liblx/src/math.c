/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lx.h"

inline int	lx_shade(int clr, double val)
{
	int r;
	int g;
	int b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = (int)(floor((clr >> 16) & 0xFF) - (((clr >> 16) & 0xFF) * val));
	g = (int)floor(((clr >> 8) & 0xFF) - (((clr >> 8) & 0xFF) * val));
	b = (int)floor(((clr) & 0xFF) - (((clr) & 0xFF) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

inline t_v3	lx_hsvtorgb(t_v3 hsv)
{
	t_v3		rgb;
	float		p;
	float		q;
	float		t;

	(hsv.x == 360.) ? (hsv.x = 0.F) : (hsv.x /= 60.);
	p = (float)(hsv.z * (1. - hsv.y));
	q = (float)(hsv.z * (1. - (hsv.y * (hsv.x - floorf(hsv.x)))));
	t = (float)(hsv.z * (1. - (hsv.y * (1. - (hsv.x - floorf(hsv.x))))));
	rgb = (t_v3){.x = 0.F, .y = 0.F, .z = 0.F};
	if (hsv.y == 0.)
		rgb = (t_v3){.x = hsv.z, .y = hsv.z, .z = hsv.z};
	else if (0. <= hsv.x && hsv.x < 1.)
		rgb = (t_v3){.x = hsv.z, .y = t, .z = p};
	else if (1. <= hsv.x && hsv.x < 2.)
		rgb = (t_v3){.x = q, .y = hsv.z, .z = p};
	else if (2. <= hsv.x && hsv.x < 3.)
		rgb = (t_v3){.x = p, .y = hsv.z, .z = t};
	else if (3. <= hsv.x && hsv.x < 4.)
		rgb = (t_v3){.x = p, .y = q, .z = hsv.z};
	else if (4. <= hsv.x && hsv.x < 5.)
		rgb = (t_v3){.x = t, .y = p, .z = hsv.z};
	else if (5. <= hsv.x && hsv.x < 6.)
		rgb = (t_v3){.x = hsv.z, .y = p, .z = q};
	return (rgb);
}

inline int	lx_rgbtohex(t_v3 rgb)
{
	int			r;
	int			g;
	int			b;

	r = (int)(rgb.x * 255.0);
	g = (int)(rgb.y * 255.0);
	b = (int)(rgb.z * 255.0);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
