/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:05:19 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/21 19:57:23 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <stdio.h>

int				is_place(t_struct *s, int y, int x)
{
	int		x_p;
	int		y_p;
	int		count_p_char;

	count_p_char = 0;
	y_p = 0;
	while (y_p < s->p.y_piece)
	{
		x_p = 0;
		while (x_p < s->p.x_piece)
		{
			if (s->p.piece[y_p][x_p] == '*')
			{
				if (y + y_p < 0 || y + y_p >= s->m.y_map ||
						x + x_p < 0 || x + x_p >= s->m.x_map ||
						(s->m.map[y + y_p][x + x_p] != '.' &&
						s->m.map[y + y_p][x + x_p] != s->p_char))
					return (0);
				if (s->m.map[y + y_p][x + x_p] == s->p_char)
					count_p_char++;
			}
			x_p++;
		}
		y_p++;
	}
	return (count_p_char == 1 ? 1 : 0);
}

t_coord_ret		resolve_map(t_struct *s)
{
	t_coord_ret	ret;
	int			x;
	int			y;

	ret.x = 0;
	ret.y = 0;
	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			if (is_place(s, y, x))
			{
				ret.x = x;
				ret.y = y;
				return (ret);
			}
			x++;
		}
		y++;
	}
	return (ret);
}
