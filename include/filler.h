/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:31:15 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/24 16:23:29 by sflinois         ###   ########.fr       */
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

typedef struct		s_enemy
{
	int				player;
	char			p_char;
	int				**t_map;
	int				t_value;	
}					t_enemy;

typedef struct		s_me
{
	int				player;
	char			p_char;
	int				**t_map;
	int				approx_points;
	int				best_coords_y;
	int				best_coords_x;
}					t_me;

typedef struct		s_struct
{
	int				error;
	t_me			me;
	t_enemy		enemy;
	t_map			m;
	t_piece			p;
}					t_struct;

typedef struct		s_strat
{
	int				st_num;
	int				(*strat)(t_struct *s);
}					t_strat;

void				free_structs(t_struct *s);
void				init_struct(t_struct *s);
int					init_player(t_struct *s);
int					init_map(t_struct *s, char **line);
int					init_piece(t_struct *s, char **line);
int					pars_map(t_struct *s, char **line);
void				check_error(t_struct *s);
void				resolve_map(t_struct *s);
int					is_place(t_struct *s, int y, int x);
void				territory_strat(t_struct *s);
void				estimate_territory(t_struct *s, int nb, int player);
void				reset_territory(t_struct *s);
void				insert_piece(t_struct *s, int y, int x);
void				delete_piece(t_struct *s, int y, int x);
#endif
