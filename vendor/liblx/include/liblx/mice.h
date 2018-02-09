/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblx/mice.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLX_MICE_H
# define LIBLX_MICE_H

# include "key.h"

#define KEYMAP_WINMAX 10
#define KEYMAP_SZ 280

typedef int		(t_micecb)(t_v2 pos, t_v2 click, void *data);

typedef struct	s_mice
{
	t_v2		pos;
	t_v2		click;
	t_micecb	*cb;
	void		*data;
	t_key		keymap[KEYMAP_WINMAX];
}				t_mice;

#endif
