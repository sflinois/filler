/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:31:15 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/21 19:14:35 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_map
{
	int				x_map;
	int				y_map;
	char			**map;
}					t_map;

typedef struct		s_piece
{
	int				x_piece;
	int				y_piece;
	char			**piece;
}					t_piece;

typedef struct		s_coord_ret
{
	int				x;
	int				y;
}					t_coord_ret;

typedef struct		s_struct
{
	int				error;
	int				player;
	char			p_char;
	t_map			m;
	t_piece			p;
}					t_struct;

void				init_struct(t_struct *s);
int					init_player(t_struct *s);
int					pars_map(t_struct *s, char **line);
int					init_map(t_struct *s, char **line);
int					init_piece(t_struct *s, char **line);
int					check_error(t_struct *s);
t_coord_ret			resolve_map(t_struct *s);

#endif
