/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:54 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:59 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(char **map)
{
	char	**result;
	int		i;

	i = 0;
	while (map[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (!result)
		return (NULL);
	while (map[i])
	{	
		result[i] = ft_strdup(map[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	is_playable(t_game *game)
{
	char	**mapcopy;
	int		error;
	int		col_c;

	error = 0;
	col_c = 0;
	mapcopy = ft_map_copy(game->map);
	if (!is_exit_reachable(game->player->x, game->player->y, mapcopy))
	{
		error = 1;
		error_message("The exit is not reachable");
	}
	free_map(mapcopy);
	mapcopy = ft_map_copy(game->map);
	is_collectible_reachable(game->player->x, game->player->y, mapcopy, &col_c);
	free_map(mapcopy);
	if (col_c != nbr_collectible(game))
	{
		error = 1;
		error_message("One of the collectible is not reachable");
	}
	return (error);
}
