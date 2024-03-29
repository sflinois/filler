/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:16:20 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:53:26 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void	free_structs(t_struct *s)
{
	int		y;

	y = 0;
	while (y < s->m.y_map)
	{
		free(s->m.map[y]);
		free(s->me.t_map[y]);
		free(s->enemy.t_map[y]);
		y++;
	}
	y = 0;
	while (y < s->p.y_piece)
	{
		free(s->p.piece[y]);
		y++;
	}
	free(s->m.map);
	free(s->me.t_map);
	free(s->enemy.t_map);
	free(s->p.piece);
}

int		main(void)
{
	t_struct	s;
	char		*line;

	init_struct(&s);
	init_player(&s);
	while (get_next_line(0, &line))
	{
		if (pars_map(&s, &line))
			return (1);
		resolve_map(&s);
		ft_printf("%d %d\n", s.me.best_coords_y, s.me.best_coords_x);
		free_structs(&s);
	}
	return (0);
}
