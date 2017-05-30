/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:32:33 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:53:48 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"

void		next_line(void)
{
	char	*line;

	if (get_next_line(0, &line))
		ft_strdel(&line);
}

void		fill_t_map(t_struct *s)
{
	int		x;
	int		y;

	y = 0;
	while (y < s->m.y_map)
	{
		x = 0;
		while (x < s->m.x_map)
		{
			if (s->m.map[y][x] == s->me.p_char)
				s->me.t_map[y][x] += s->m.y_map + s->m.x_map;
			if (s->m.map[y][x] == s->enemy.p_char)
				s->enemy.t_map[y][x] += s->m.y_map + s->m.x_map;
			x++;
		}
		y++;
	}
}

void		get_map(t_struct *s, char **line)
{
	int		y;
	int		y_len;

	s->error = init_map(s, line);
	next_line();
	y = 0;
	y_len = 0;
	while (y < s->m.y_map && !s->error)
	{
		get_next_line(0, line);
		while (ft_isdigit((*line)[y_len]))
			y_len++;
		if (!(s->m.map[y] = ft_strdup(*line + y_len + 1)))
			s->error = 1;
		ft_strdel(line);
		y++;
	}
	fill_t_map(s);
}

void		get_piece(t_struct *s, char **line)
{
	int		y;

	s->error = init_piece(s, line);
	y = 0;
	while (y < s->p.y_piece && !s->error)
	{
		get_next_line(0, line);
		if (!(s->p.piece[y] = ft_strdup(*line)))
			s->error = 1;
		ft_strdel(line);
		y++;
	}
}

int			pars_map(t_struct *s, char **line)
{
	get_map(s, line);
	get_piece(s, line);
	check_error(s);
	return (s->error);
}
