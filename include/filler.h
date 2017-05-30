/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:31:15 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:55:10 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct		s_me
{
	int				player;
	char			p_char;
	int				**t_map;
	int				approx_points;
	int				best_coords_y;
	int				best_coords_x;
}					t_me;

typedef struct		s_enemy
{
	int				player;
	char			p_char;
	int				t_value;
	int				**t_map;
}					t_enemy;

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

typedef struct		s_struct
{
	int				error;
	char			**prev_map;
	t_me			me;
	t_enemy			enemy;
	t_map			m;
	t_piece			p;
}					t_struct;

void				free_structs(t_struct *s);
void				free_map(t_struct *s);
void				init_struct(t_struct *s);
int					init_player(t_struct *s);
int					init_map(t_struct *s, char **line);
int					init_piece(t_struct *s, char **line);
int					pars_map(t_struct *s, char **line);
void				check_error(t_struct *s);
void				resolve_map(t_struct *s);
int					is_place(t_struct *s, int y, int x);
int					count_territory_me(t_struct *s, int y, int x, int nb);
int					count_territory_enemy(t_struct *s, int y, int x, int nb);
int					count_t_x_me(t_struct *s, int y, int x, int nb);
int					count_t_y_me(t_struct *s, int y, int x, int nb);
int					count_t_x_enemy(t_struct *s, int y, int x, int nb);
int					count_t_y_enemy(t_struct *s, int y, int x, int nb);
void				estimate_territory(t_struct *s, int nb, int player);
void				reset_territory(t_struct *s);
void				insert_piece(t_struct *s, int y, int x);
void				delete_piece(t_struct *s, int y, int x);

#endif
