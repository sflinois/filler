/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:05:19 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/23 18:29:08 by sflinois         ###   ########.fr       */
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
						s->m.map[y + y_p][x + x_p] != s->me.p_char))
					return (0);
				if (s->m.map[y + y_p][x + x_p] == s->me.p_char)
					count_p_char++;
			}
			x_p++;
		}
		y_p++;
	}
	return (count_p_char == 1 ? 1 : 0);
}

void			resolve_map(t_struct *s)
{
	//int					i;
	//int					strat;
	//static const t_strat st_tab[] = {
	//					{1, (*applystrat_territory)},
	//					{-1, NULL},
	//					};

	//i = 0;
	territory_strat(s);
}
