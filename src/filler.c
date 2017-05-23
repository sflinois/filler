/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:16:20 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/23 19:01:43 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <sys/uio.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/*
void	free_struct(s);
{
	int		y;
	
	y = 0;
}
*/
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
		if (check_error(&s))
			return (1);
		resolve_map(&s);
		ft_printf("%d %d\n", s.me.best_coords_y, s.me.best_coords_x);
		//free_structs(s);
	}
	return (0);
}
