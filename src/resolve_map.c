/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:05:19 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:53:59 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"

int			is_place(t_struct *s, int y, int x)
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
				if (y + y_p < 0 || y + y_p >= s->m.y_map || x + x_p < 0 ||
						x + x_p >= s->m.x_map || (s->m.map[y + y_p][x + x_p]
						!= '.' && s->m.map[y + y_p][x + x_p] != s->me.p_char))
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

int			get_points(t_struct *s, int player)
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
			if (player == s->me.player)
				points += s->me.t_map[y][x] - s->enemy.t_map[y][x] > 0 ? 1 : 0;
			if (player == s->enemy.player)
				points += s->enemy.t_map[y][x] - s->me.t_map[y][x] > 0 ? 1 : 0;
			x++;
		}
		y++;
	}
	return (points);
}

int			get_t_value(t_struct *s, int player)
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
			if (player == s->me.player)
				points += s->me.t_map[y][x];
			if (player == s->enemy.player)
				points += s->enemy.t_map[y][x];
			x++;
		}
		y++;
	}
	return (points);
}

void		estimate_points(t_struct *s, int y, int x)
{
	int		me_points;
	int		enemy_t_value;

	insert_piece(s, y, x);
	estimate_territory(s, s->m.y_map + s->m.x_map, s->me.player);
	estimate_territory(s, s->m.y_map + s->m.x_map, s->enemy.player);
	me_points = get_points(s, s->me.player);
	enemy_t_value = get_t_value(s, s->enemy.player);
	if (me_points > s->me.approx_points)
	{
		s->me.approx_points = me_points;
		s->me.best_coords_y = y;
		s->me.best_coords_x = x;
	}
	else if (me_points == s->me.approx_points &&
			enemy_t_value < s->enemy.t_value)
	{
		s->enemy.t_value = enemy_t_value;
		s->me.best_coords_y = y;
		s->me.best_coords_x = x;
	}
	reset_territory(s);
	delete_piece(s, y, x);
}

void		resolve_map(t_struct *s)
{
	int		x;
	int		y;

	s->me.approx_points = 0;
	s->enemy.t_value = (s->m.y_map + s->m.x_map) *
		s->m.y_map * s->m.x_map;
	y = 0 - s->p.y_piece;
	while (y < s->m.y_map)
	{
		x = 0 - s->p.x_piece;
		while (x < s->m.x_map)
		{
			if (is_place(s, y, x))
				estimate_points(s, y, x);
			x++;
		}
		y++;
	}
}
