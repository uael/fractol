/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLX_H
# define LIBLX_H

#include "liblx/img.h"
#include "liblx/key.h"
#include "liblx/mice.h"
#include "liblx/win.h"

extern int	lx_ctor(void);
extern int	lx_run(void);
extern void	lx_dtor(void);

extern int	lx_hookkey(int key, t_keycb *cb, void *data);
extern int	lx_hookmv(t_win *win, t_micecb *cb, void *data);
extern int	lx_hookbtn(t_win *win, int event, int mask, t_event *cb);
extern int	lx_hookexpose(t_win *win, t_event *event);

extern int	lx_shade(int clr, double val);
extern t_v3	lx_hsvtorgb(t_v3 hsv);
extern int	lx_rgbtohex(t_v3 rgb);

#endif
