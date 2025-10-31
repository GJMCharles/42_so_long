/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:09:26 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:09:27 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nbr_collectible(t_game *game)
{
	int	i;

	i = 0;
	if (!game->food_list)
		return (0);
	while (game->food_list[i])
	{
		i++;
	}
	return (i);
}

int	valid_nbr_player(char **map)
{
	int	cpt_player;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_player = 0;
	if (!map)
	{
		error_message("Parsing failed");
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'P')
				cpt_player++;
		i++;
	}
	if (cpt_player != 1)
		return (error_message("More or less than 1 player"), 1);
	return (0);
}

int	valid_nbr_exit(char **map)
{
	int	cpt_sortie;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_sortie = 0;
	if (!map)
	{
		error_message("Parsing failed");
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'E')
				cpt_sortie++;
		i++;
	}
	if (cpt_sortie != 1)
		return (error_message("There is more or less than 1 exit"), 1);
	return (0);
}

int	valid_nbr_collectibles(char **map)
{
	int	cpt_collectibles;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_collectibles = 0;
	if (!map)
	{
		error_message("Parsing failed");
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'E')
				cpt_collectibles++;
		i++;
	}
	if (cpt_collectibles < 1)
		return (1);
	return (0);
}

int	valid_map_requirement(char **map)
{
	if (valid_nbr_player(map))
		return (1);
	else if (valid_nbr_exit(map))
		return (1);
	else if (valid_nbr_collectibles(map))
		return (1);
	else
		return (0);
}
