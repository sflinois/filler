/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:16:20 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/17 18:06:11 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <sys/uio.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		check_first_line(char **buff, t_struct *s)
{
	int		i;
	char	*ref_p1;
	
	s->player = 0;
	ref_p1 = "$$$ exec p1 : [../sflinois.filler]";
	i = 0;
	while (*buff[i] && ref_p1[i] && *buff[i] == ref_p1[i])
		i++;
	s->player = *buff[i] == '\n' ? 1 : 2;
	while (*buff[i] && *buff[i] != '\n')
		i++;
	*buff = *buff + i; 
	return (s->player ? 1 : 0);
}

int		check_map(char **buff, t_struct *s)
{
	int		i;
	int		x;
	int		y;
	
	i = 0;
	// go au permier digit
	while (*buff[i] && !ft_isdigit(*buff[i]))
		i++;
	s->x_map = ft_atoi(*buff[i])
	//go au deuxieme digit
	while (*buff[i] && ft_isdigit(*buff[i]))
		i++;
	s->y_map = ft_atoi(*buff[i + 1]);
	while (*buff[i] && *buff[i] != '\n')
		i++;
	i++;
	//debut deuxieme ligne
	while (*buff[i] && *buff[i] != '\n')
		i++;
	buff += i + 1;
	//debut troisieme ligne
	s->map = (char **)malloc(sizeof(char *) * s->x_map);
	x = 0;
	while (x < s->x_map)
	{
		y = 0;
		s->map[x] = (char *)malloc(sizeof(char *) * s->y_map);
		while (y < s->y_map)
		{
			s->map[x][y] = *(buff[4 + y + x * (s->y_map + 5)]) 
			y++;
		}
		x++;
	}
	*buff += s->x_map * (s->y_map + 5);
	return (1);
}

int		check_piece(char **buff, t_struct s)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	// go au permier digit
	while (*buff[i] && !ft_isdigit(*buff[i]))
		i++;
	s->x_piece = ft_atoi(*buff[i])
	//go au deuxieme digit
	while (*buff[i] && ft_isdigit(*buff[i]))
		i++;
	s->y_piece = ft_atoi(*buff[i + 1]);
	while (*buff[i] && *buff[i] != '\n')
		i++;
	i++;
	//debut deuxieme ligne
	s->piece = (char **)malloc(sizeof(char *) * s->x_piece);
	x = 0;
	while (x < s->x_piece)
	{
		y = 0;
		s->piece[x] = (char *)malloc(sizeof(char *) * s->y_piece);
		while (y < s->y_piece)
		{
			s->piece[x][y] = *(buff[y + x * (s->y_piece + 1)]) 
			y++;
		}
		x++;
	}
}

int		pars_map(t_struct *s)
{
	//int		fd_log;
	char 	buff[100000];
	int		ret

	ft_bzero(buff, 100000);
	//fd_log = open("../log", O_WRONLY);
	read(0, &buff, 100000);
	ret = check_first_line(&buff, s);
	ret	= check_map(&buff, s);
	ret = check_piece(&buff, s);
	//write(fd_log, buff, ft_strlen(buff));
	//close(fd_log);
	fprintf(stderr, "Salut o/%s\n", "");
	return (ft_atoi(buff + 10));
}

int		main(void)
{
	int			i;
	t_struct	s;

	i = pars_map(&s);
	if (i == 1)
		ft_printf("%d %d\n", 8, 3);
	else
		ft_printf("%d %d\n", 12, 14);
	return (0);
}
