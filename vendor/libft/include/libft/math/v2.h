/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/math/v2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:28:45 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/10 10:34:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_V2_H
# define LIBFT_MATH_V2_H

# include <math.h>

typedef struct	s_v2
{
	float		x;
	float		y;
}				t_v2;

extern t_v2		ft_v2(float x, float y);

#endif
