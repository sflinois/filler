/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:47:44 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/24 15:28:15 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <string.h>
#include <stdio.h>

void		init_struct(t_struct *s)
{
	s->error = 0;
	s->m.y_map = 0;
	s->m.x_map = 0;
	s->m.map = NULL;
	s->p.y_piece = 0;
	s->p.x_piece = 0;
	s->p.piece = NULL;
	s->me.best_coords_y = 0;
	s->me.best_coords_x = 0;
}

int			init_player(t_struct *s)
{
	char	*line;

	if (!get_next_line(0, &line))
		return (1);
	if (ft_strncmp("$$$ exec p", line, 10))
	{
		ft_strdel(&line);
		return (1);
	}
	s->me.player = ft_atoi(line + 10);
	s->enemy.player = s->me.player == 1 ? 2 : 1;
	s->me.p_char = s->me.player == 1 ? 'O' : 'X';
	s->enemy.p_char = s->enemy.player == 1 ? 'O' : 'X';
	ft_strdel(&line);
	return (0);
}

int			init_t_map(t_struct *s)
{
	int		y;

	if (!(s->me.t_map = (int**)ft_memalloc(sizeof(int*) * s->m.y_map)))
		return (1);
	if (!(s->enemy.t_map = (int**)ft_memalloc(sizeof(int*) * s->m.y_map)))
		return (1);
	y = 0;
	while (y < s->m.y_map)
	{
		if (!(s->me.t_map[y] = (int*)ft_memalloc(sizeof(int) * s->m.x_map)))
			return (1);
		if (!(s->enemy.t_map[y] = (int*)ft_memalloc(sizeof(int) * s->m.x_map)))
			return (1);
		y++;
	}
	return (0);
}

int			init_map(t_struct *s, char **line)
{
	if (ft_strncmp("Plateau", *line, 7) || s->error)
	{
		ft_strdel(line);
		return (1);
	}
	s->m.y_map = ft_atoi(ft_strchr(*line, ' ') + 1);
	s->m.x_map = ft_atoi(ft_strrchr(*line, ' ') + 1);
	ft_strdel(line);
	if (!(s->m.map = (char**)ft_memalloc(sizeof(char*) * s->m.y_map)))
		return (1);
	return (init_t_map(s));
}

int			init_piece(t_struct *s, char **line)
{
	if (!get_next_line(0, line))
		return (1);
	if (ft_strncmp("Piece", *line, 5) || s->error)
	{
		ft_strdel(line);
		return (1);
	}
	s->p.y_piece = ft_atoi(ft_strchr(*line, ' ') + 1);
	s->p.x_piece = ft_atoi(ft_strrchr(*line, ' ') + 1);
	ft_strdel(line);
	if (!(s->p.piece = (char**)ft_memalloc(sizeof(char*) * s->p.y_piece)))
		return (1);
	return (0);
}
