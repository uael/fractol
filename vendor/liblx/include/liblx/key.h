/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblx/key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/09 07:00:16 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLX_KEY_H
# define LIBLX_KEY_H

# include <libft.h>

# define LX_KEYPRESS 2
# define LX_KEYRELEASE 3
# define LX_MOTIONNOTIFY 6
# define LX_KEYPRESSMASK (1L<<0)
# define LX_KEYRELEASEMASK (1L<<1)
# define LX_BUTTON3MOTIONMASK (1L<<10)
# define LX_BUTTON4MOTIONMASK (1L<<11)
# define LX_BUTTON5MOTIONMASK (1L<<12)
# define LX_BUTTONMOTIONMASK (1L<<13)
# define LX_KEYMAPSTATEMASK (1L<<14)
# define LX_EXPOSUREMASK (1L<<15)
# define LX_VISIBILITYCHANGEMASK (1L<<16)
# define LX_STRUCTURENOTIFYMASK (1L<<17)
# define LX_RESIZEREDIRECTMASK (1L<<18)
# define LX_SUBSTRUCTURENOTIFYMASK (1L<<19)
# define LX_BUTTONPRESSMASK (1L<<2)
# define LX_SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define LX_FOCUSCHANGEMASK (1L<<21)
# define LX_PROPERTYCHANGEMASK (1L<<22)
# define LX_COLORMAPCHANGEMASK (1L<<23)
# define LX_BUTTONRELEASEMASK (1L<<3)
# define LX_ENTERWINDOWMASK (1L<<4)
# define LX_LEAVEWINDOWMASK (1L<<5)
# define LX_POINTERMOTIONMASK (1L<<6)
# define LX_POINTERMOTIONHINTMASK (1L<<7)
# define LX_BUTTON1MOTIONMASK (1L<<8)
# define LX_BUTTON2MOTIONMASK (1L<<9)

# define LX_KEYA 0
# define LX_KEYS 1
# define LX_KEYD 2
# define LX_KEYF 3
# define LX_KEYH 4
# define LX_KEYG 5
# define LX_KEYZ 6
# define LX_KEYX 7
# define LX_KEYC 8
# define LX_KEYV 9
# define LX_KEYB 11
# define LX_KEYQ 12
# define LX_KEYW 13
# define LX_KEYE 14
# define LX_KEYR 15
# define LX_KEYY 16
# define LX_KEYT 17
# define LX_KEYONE 18
# define LX_KEYTWO 19
# define LX_KEYTHREE 20
# define LX_KEYFOUR 21
# define LX_KEYSIX 22
# define LX_KEYFIVE 23
# define LX_KEYNINE 25
# define LX_KEYSEVEN 26
# define LX_KEYEIGHT 28
# define LX_KEYZERO 29
# define LX_KEYBRACE_R 30
# define LX_KEYO 31
# define LX_KEYU 32
# define LX_KEYBRACE_L 33
# define LX_KEYI 34
# define LX_KEYP 35
# define LX_KEYL 37
# define LX_KEYJ 38
# define LX_KEYK 40
# define LX_KEYSEMI 41
# define LX_KEYN 45
# define LX_KEYM 46
# define LX_KEYTAB 48
# define LX_KEYPLUS 69
# define LX_KEYMINUS 78
# define LX_KEYLEFT 123
# define LX_KEYRIGHT 124
# define LX_KEYDOWN 125
# define LX_KEYUP 126
# define LX_KEYESC 53

typedef int		(t_keycb)(int key, int status, void *data);

typedef struct	s_key
{
	void		*data;
	int			status;
	t_keycb		*cb;
	uint32_t	tick;
}				t_key;

#endif
