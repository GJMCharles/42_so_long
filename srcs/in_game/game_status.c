/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:12 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_door_open(t_game *game)
{
	int	count_eaten;
	int	i;

	if (!game->food_list)
		return ;
	i = 0;
	count_eaten = 0;
	while (game->food_list[i])
	{
		if (game->food_list[i]->eaten)
			count_eaten++;
		i++;
	}
	if (count_eaten == i)
		game->exit->is_open = 1;
}

void	eat_collectible(int x, int y, t_game *game)
{
	int	i;

	i = 0;
	while (game->food_list[i])
	{
		if (game->food_list[i]->x == x && game->food_list[i]->y == y)
		{
			game->food_list[i]->eaten = 1;
			is_door_open(game);
		}
		i++;
	}
}
