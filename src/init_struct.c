/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:47:44 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/21 19:52:26 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <string.h>
#include <stdio.h>

void		init_struct(t_struct *s)
{
	s->error = 0;
	s->player = 0;
	s->m.y_map = 0;
	s->m.x_map = 0;
	s->m.map = NULL;
	s->p.y_piece = 0;
	s->p.x_piece = 0;
	s->p.piece = NULL;
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
	s->player = ft_atoi(line + 10);
	if (s->player == 1)
		s->p_char = 'O';
	else if (s->player == 2)
		s->p_char = 'X';
	ft_strdel(&line);
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
	return (0);
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
