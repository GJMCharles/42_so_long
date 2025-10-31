/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:08:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:08:08 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/incs/ft_printf.h"
# include "../mlx/mlx.h"

typedef struct t_Player
{
	int		x;
	int		y;
	int		w;
}				t_Player;

typedef struct t_Exit
{
	int		x;
	int		y;
	int		is_open;
}				t_Exit;

typedef struct t_Food
{
	int		x;
	int		y;
	int		eaten;
}				t_Food;

typedef struct t_Texture
{
	void	*c_d;
	void	*o_d;
	void	*gro;
	void	*wal;
	void	*pla;
	void	*col;
	int		h;
	int		w;
}				t_Texture;

typedef struct t_Windows
{
	int	h;
	int	w;
}				t_Windows;

typedef struct t_Mlx_data
{
	void		*mlx;
	void		*mlx_win;
	t_Windows	win;
}				t_Mlx_data;

typedef struct t_Game
{
	char		**map;
	t_Player	*player;
	t_Exit		*exit;
	t_Food		**food_list;
	t_Mlx_data	d;
	t_Texture	*t;
	int			moov;
}				t_Game;

typedef struct t_nk
{
	int	i;
	int	j;
}				t_nk;

t_Game		*create_game(int fd);
t_Game		*init_struct(int fd);

t_Exit		*create_exit(int x, int y);

t_Food		*create_food(int x, int y);

t_Player	*create_player(int x, int y);

int			nbr_collectible(t_Game *game);
int			is_playable(t_Game *game);
int			ft_check_map(t_Game *game);
int			create_map(t_Game *game, int *cpt_food);
int			is_exit_reachable(int x, int y, char **map);
void		is_collectible_reachable(int x, int y, char **map, int *cpt);
int			valid_map_requirement(char **map);
int			verif_ext(char *str);

void		free_game(t_Game *game);
void		free_game_2(t_Game *game);
void		is_door_open(t_Game *game);
void		ft_move_d(t_Game *game);
void		ft_move_w(t_Game *game);
void		ft_move_s(t_Game *game);
void		ft_move_a(t_Game *game);
void		init_texture(t_Game *game);
void		render_map(t_Game *game);
void		clear_image(t_Game *game);
void		eat_collectible(int x, int y, t_Game *game);
void		ft_parser(int fd, char ***map);
void		free_map(char **map);
void		ft_print_map(char **map);

#endif
