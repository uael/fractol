/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lx.h"

t_lx		*g_lx = NULL;
static t_lx	g_lx_stack = {
	NULL, NULL, 0, NULL, 0, NULL, { { NULL, 0, NULL, 0 } }
};

inline int			lx_ctor(void)
{
	g_lx = &g_lx_stack;
	if (!(g_lx->ptr = mlx_init()))
		return (WUT);
	return (YEP);
}

static inline int	tick(void *data)
{
	t_lx *lx;
	
	lx = data;
	++lx->tick;
	if (lx->loop != NULL)
		lx->loop(data);
	return (lx->tick);
}

inline int			lx_run(void)
{
	static int running = 0;

	if (!g_lx || !g_lx->ptr)
		return (WUT);
	if (!running)
	{
		running = 1;
		mlx_do_key_autorepeatoff(g_lx->ptr);
		mlx_loop_hook(g_lx->ptr, tick, g_lx);
		mlx_loop(g_lx->ptr);
	}
	return (YEP);
}

inline void			lx_dtor(void)
{
	if (g_lx && g_lx->ptr)
		mlx_do_key_autorepeaton(g_lx->ptr);
}
