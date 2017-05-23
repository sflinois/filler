/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:02:32 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/23 20:00:44 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <stdio.h>

int			get_points(t_struct *s)
{
	int		y;
	int		x;
	int		points;

	points = 0;
	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			points += s->me.t_map[y][x] - s->enemy.t_map[y][x] > 0 ? 1 : 0;
			x++;
		}
		y++;
	}
	return (points);
}

void		estimate_points(t_struct *s, int y, int	x)
{
	int		points;

	insert_piece(s, y, x);
	estimate_territory(s, s->m.y_map + s->m.x_map, s->me.player);
	estimate_territory(s, s->m.y_map + s->m.x_map, s->enemy.player);
	points = get_points(s);
	if (points > s->me.approx_points)
	{
		s->me.approx_points = points;
		s->me.best_coords_y = y;
		s->me.best_coords_x = x;
	}
	reset_territory(s);
	delete_piece(s, y, x);
}

void		territory_strat(t_struct *s)
{
	int		x;
	int		y;

	s->me.approx_points = 0;
	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			if (is_place(s, y, x))
				estimate_points(s, y, x);
			x++;
		}
		y++;
	}
}
