/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:16:20 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/21 20:06:09 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/libft.h"
#include <sys/uio.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	t_struct	s;
	t_coord_ret	c;
	

	init_struct(&s);
	if (pars_map(&s))
		return (1);
	if (check_error(&s))
		return (1);
	c = resolve_map(&s);
	ft_printf("%d %d\n", c.y, c.x);
	while (1)
		ft_printf("%d %d\n", c.y, c.x);
	return (0);
}
