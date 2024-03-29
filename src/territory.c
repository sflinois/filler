/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   territory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:14:43 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:54:11 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"

void		insert_piece(t_struct *s, int y, int x)
{
	char	low_p_char;
	int		x_p;
	int		y_p;

	low_p_char = s->me.p_char == 'O' ? 'o' : 'x';
	y_p = 0;
	while (y_p < s->p.y_piece)
	{
		x_p = 0;
		while (x_p < s->p.x_piece)
		{
			if (s->p.piece[y_p][x_p] == '*'
					&& s->p.piece[y_p][x_p] != s->me.p_char)
			{
				s->m.map[y + y_p][x + x_p] = low_p_char;
				s->me.t_map[y + y_p][x + x_p] = s->m.y_map + s->m.x_map;
			}
			x_p++;
		}
		y_p++;
	}
}

void		delete_piece(t_struct *s, int y, int x)
{
	char	low_p_char;
	int		x_p;
	int		y_p;

	low_p_char = s->me.p_char == 'O' ? 'o' : 'x';
	y_p = 0;
	while (y_p < s->p.y_piece)
	{
		x_p = 0;
		while (x_p < s->p.x_piece)
		{
			if (s->p.piece[y_p][x_p] == '*'
					&& s->p.piece[y_p][x_p] != s->me.p_char)
			{
				s->m.map[y + y_p][x + x_p] = '*';
				s->me.t_map[y + y_p][x + x_p] = 0;
			}
			x_p++;
		}
		y_p++;
	}
}

int			count_territory_me(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (s->me.t_map[y][x] == nb)
	{
		count += count_t_y_me(s, y, x, nb);
		count += count_t_x_me(s, y, x, nb);
	}
	return (count);
}

void		estimate_territory(t_struct *s, int nb, int player)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			if (player == s->me.player)
				count += count_territory_me(s, y, x, nb);
			else
				count += count_territory_enemy(s, y, x, nb);
			x++;
		}
		y++;
	}
	if (count)
		estimate_territory(s, nb - 1, player);
}

void		reset_territory(t_struct *s)
{
	int		y;
	int		x;

	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			if (s->me.t_map[y][x] != s->m.y_map + s->m.x_map)
				s->me.t_map[y][x] = 0;
			if (s->enemy.t_map[y][x] != s->m.y_map + s->m.x_map)
				s->enemy.t_map[y][x] = 0;
			x++;
		}
		y++;
	}
}
