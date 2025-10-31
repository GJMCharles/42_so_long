/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:41 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:43 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Player	*create_player(int x, int y)
{
	t_Player	*player;

	player = malloc(sizeof(t_Player));
	if (!player)
		return (NULL);
	player->x = x;
	player->y = y;
	player->w = 0;
	return (player);
}

t_Food	*create_food(int x, int y)
{
	t_Food	*food;

	food = malloc(sizeof(t_Food));
	if (!food)
		return (NULL);
	food->eaten = 0;
	food->x = x;
	food->y = y;
	return (food);
}

t_Exit	*create_exit(int x, int y)
{
	t_Exit	*exit;

	exit = malloc(sizeof(t_Exit));
	if (!exit)
		return (NULL);
	exit->is_open = 0;
	exit->x = x;
	exit->y = y;
	return (exit);
}

void	add_food(int cpt_food, t_Game *game)
{
	int			i;
	int			j;
	int			cpt;

	cpt = 0;
	i = 0;
	j = 0;
	game->food_list = malloc(sizeof(t_Food) * (cpt_food + 1));
	if (!game->food_list)
		return ;
	while (game->map[i] && cpt < cpt_food)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				game->food_list[cpt] = create_food(i, j);
				cpt++;
			}
			j++;
		}
		i++;
	}
	game->food_list[cpt] = NULL;
}

t_Game	*create_game(int fd)
{
	t_Game	*game;
	int		cpt_food;

	cpt_food = 0;
	game = malloc(sizeof(t_Game));
	if (!game)
		return (NULL);
	ft_parser(fd, &(game->map));
	close(fd);
	if (!game->map || valid_map_requirement(game->map))
	{
		if (game->map)
			free_map(game->map);
		else
			ft_putstr_fd("Error\nInvalid Map", 2);
		free(game);
		exit(0);
	}
	if (create_map(game, &cpt_food) || cpt_food == 0)
	{
		if (cpt_food == 0)
			ft_putstr_fd("Error\nNo collectibles", 2);
		return (free_game(game), NULL);
	}
	return (add_food(cpt_food, game), game);
}
