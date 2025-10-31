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

# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct t_player
{
	int		x;
	int		y;
	int		w;
}				t_player;

typedef struct t_exit
{
	int		x;
	int		y;
	int		is_open;
}				t_exit;

typedef struct t_food
{
	int		x;
	int		y;
	int		eaten;
}				t_food;

typedef struct t_texture
{
	void	*c_d;
	void	*o_d;
	void	*gro;
	void	*wal;
	void	*pla;
	void	*col;
	int		h;
	int		w;
}				t_texture;

typedef struct t_windows
{
	int	h;
	int	w;
}				t_windows;

typedef struct t_mlx_data
{
	void		*mlx;
	void		*mlx_win;
	t_windows	win;
}				t_mlx_data;

typedef struct t_game
{
	char		**map;
	t_player	*player;
	t_exit		*exit;
	t_food		**food_list;
	t_mlx_data	d;
	t_texture	*t;
	int			moov;
}				t_game;

typedef struct t_nk
{
	int	i;
	int	j;
}				t_nk;

void		error_message(char *message);

t_game		*create_game(int fd);
t_game		*init_struct(int fd);

t_exit		*create_exit(int x, int y);

t_food		*create_food(int x, int y);

t_player	*create_player(int x, int y);

int			nbr_collectible(t_game *game);
int			is_playable(t_game *game);
int			ft_check_map(t_game *game);
int			create_map(t_game *game, int *cpt_food);
int			is_exit_reachable(int x, int y, char **map);
void		is_collectible_reachable(int x, int y, char **map, int *cpt);
int			valid_map_requirement(char **map);
int			verif_ext(char *str);

void		free_game(t_game *game);
void		free_game_2(t_game *game);
void		is_door_open(t_game *game);
void		ft_move_d(t_game *game);
void		ft_move_w(t_game *game);
void		ft_move_s(t_game *game);
void		ft_move_a(t_game *game);
void		init_texture(t_game *game);
void		render_map(t_game *game);
void		clear_image(t_game *game);
void		eat_collectible(int x, int y, t_game *game);
void		ft_parser(int fd, char ***map);
void		free_map(char **map);
void		ft_print_map(char **map);

#endif
