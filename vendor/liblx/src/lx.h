/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LX_H
# define LX_H

#include <mlx.h>

#include "liblx.h"

struct s_lx;

typedef int		(t_lxloop)(struct s_lx *lx);

typedef struct	s_lx
{
	void		*ptr;
	t_win		*wins;
	size_t		nwin;
	t_win		*focused;
	uint32_t	tick;
	t_lxloop	*loop;
	t_key		keymap[KEYMAP_SZ];
}				t_lx;

extern t_lx		*g_lx;

#endif
