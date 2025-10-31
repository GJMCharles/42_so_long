/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:20 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:21 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_w(t_game *game)
{
	int		x;
	int		y;
	char	tmp;

	x = game->player->x;
	y = game->player->y;
	tmp = game->map[x - 1][y];
	if (x - 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	else
	{
		game->map[x][y] = '0';
		if (game->map[x - 1][y] == 'C')
			eat_collectible(x - 1, y, game);
		game->map[x - 1][y] = 'P';
		game->player->x = x - 1;
		game->moov++;
		ft_printf("%d moves\n", game->moov);
	}
}

void	ft_move_s(t_game *game)
{
	int		x;
	int		y;
	char	tmp;

	x = game->player->x;
	y = game->player->y;
	tmp = game->map[x + 1][y];
	if (x + 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	else
	{
		game->map[x][y] = '0';
		if (game->map[x + 1][y] == 'C')
			eat_collectible(x + 1, y, game);
		game->map[x + 1][y] = 'P';
		game->player->x = x + 1;
		game->moov++;
		ft_printf("%d moves\n", game->moov);
	}
}

void	ft_move_a(t_game *game)
{
	int		x;
	int		y;
	char	tmp;

	x = game->player->x;
	y = game->player->y;
	tmp = game->map[x][y - 1];
	if (y - 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	else
	{
		game->map[x][y] = '0';
		if (game->map[x][y - 1] == 'C')
			eat_collectible(x, y - 1, game);
		game->map[x][y - 1] = 'P';
		game->player->y = y - 1;
		game->moov++;
		ft_printf("%d moves\n", game->moov);
	}
}

void	ft_move_d(t_game *game)
{
	int		x;
	int		y;
	char	tmp;

	x = game->player->x;
	y = game->player->y;
	tmp = game->map[x][y + 1];
	if (y + 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	else
	{
		game->map[x][y] = '0';
		if (game->map[x][y + 1] == 'C')
			eat_collectible(x, y + 1, game);
		game->map[x][y + 1] = 'P';
		game->player->y = y + 1;
		game->moov++;
		ft_printf("%d moves\n", game->moov);
	}
}
