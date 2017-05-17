/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:20:12 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/17 16:58:12 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_struct
{
	int				player;
	int				x_map;
	int				y_map;
	char			**map;
	int				x_piece;
	int				y_piece;
	char			**piece;
}					t_struct;

#endif
