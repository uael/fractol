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

inline int	lx_hookkey(int key, t_keycb *cb, void *data)
{
	if (key > KEYMAP_WINMAX)
	{
		errno = EINVAL;
		return (WUT);
	}
	g_lx->keymap[key] = (t_key){
		.status = 0,
		.cb = cb,
		.data = data,
		.tick = 1
	};
	return (YEP);
}
