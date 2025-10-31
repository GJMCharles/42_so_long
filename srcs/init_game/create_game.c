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

t_player	*create_player(int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = x;
	player->y = y;
	player->w = 0;
	return (player);
}

t_food	*create_food(int x, int y)
{
	t_food	*food;

	food = malloc(sizeof(t_food));
	if (!food)
		return (NULL);
	food->eaten = 0;
	food->x = x;
	food->y = y;
	return (food);
}

t_exit	*create_exit(int x, int y)
{
	t_exit	*exit;

	exit = (t_exit *) malloc(sizeof(t_exit));
	if (!exit)
		return (NULL);
	exit->is_open = 0;
	exit->x = x;
	exit->y = y;
	return (exit);
}

void	add_food(int cpt_food, t_game *game)
{
	int			i;
	int			j;
	int			cpt;

	cpt = 0;
	i = 0;
	j = 0;
	game->food_list = malloc(sizeof(t_food) * (cpt_food + 1));
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

t_game	*create_game(int fd)
{
	t_game	*game;
	int		cpt_food;

	cpt_food = 0;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_parser(fd, &(game->map));
	if (!game->map || valid_map_requirement(game->map))
	{
		if (game->map)
			free_map(game->map);
		else
			error_message("Invalid Map");
		free(game);
		exit(0);
	}
	if (create_map(game, &cpt_food) || cpt_food == 0)
	{
		if (cpt_food == 0)
			error_message("No collectibles");
		return (free_game(game), NULL);
	}
	return (add_food(cpt_food, game), game);
}
