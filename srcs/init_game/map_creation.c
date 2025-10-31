/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:10:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:27:24 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(t_Game *game, int *cpt_food)
{
	int	i;
	int	j;

	i = 0;
	game->player = NULL;
	game->exit = NULL;
	game->food_list = NULL;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player = create_player(i, j);
			else if (game->map[i][j] == 'E')
				game->exit = create_exit(i, j);
			else if (game->map[i][j] == 'C')
				*cpt_food += 1;
			else if (!ft_strchr("01CPE", game->map[i][j]))
				return (ft_putstr_fd("Error:\nInvalid map\n", 2), 1);
			j++;
		}
	}
	return (0);
}

int	calc_h(t_Game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return (0);
	while (game->map[i])
		i++;
	return (64 * i);
}

int	calc_w(t_Game *game)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(game->map[0]);
	return (i * 64);
}

t_Game	*init_struct(int fd)
{
	t_Game	*game;

	game = create_game(fd);
	close(fd);
	if (!game)
	{
		ft_putstr_fd("Error:\nMap creation has failed\n", 2);
		exit (0);
	}
	game->d.mlx = NULL;
	game->d.mlx_win = NULL;
	if (ft_check_map(game) || valid_map_requirement(game->map))
		free_game(game);
	game->d.win.w = calc_w(game);
	game->d.win.h = calc_h(game);
	if (game->d.win.h > 1080 || game->d.win.w > 1920)
	{
		ft_putstr_fd("Error\nMap Bigger than screen", 2);
		free_game(game);
	}
	game->moov = 0;
	return (game);
}
