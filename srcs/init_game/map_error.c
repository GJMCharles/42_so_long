/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:27:33 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:27:34 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit_reachable(int x, int y, char **map)
{
	if (map[x] && (map[x][y] == '1' || map[x][y] == 'V' || x < 0 || y < 0))
		return (0);
	else if (map[x][y] == 'E')
		return (1);
	map[x][y] = 'V';
	if (is_exit_reachable (x + 1, y, map)
		|| is_exit_reachable (x - 1, y, map)
		|| is_exit_reachable (x, y + 1, map)
		|| is_exit_reachable (x, y - 1, map))
		return (1);
	else
		return (0);
}

void	is_collectible_reachable(int x, int y, char **map, int *cpt)
{
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'E')
		return ;
	else if (map[x][y] == 'C')
	{
		*cpt += 1;
		map[x][y] = '0';
		return ;
	}
	map[x][y] = 'V';
	is_collectible_reachable(x + 1, y, map, cpt);
	is_collectible_reachable(x - 1, y, map, cpt);
	is_collectible_reachable(x, y + 1, map, cpt);
	is_collectible_reachable(x, y - 1, map, cpt);
}

static int	is_closed_map(char **map)
{
	int		error;
	int		i;
	int		j;

	j = 0;
	i = 0;
	error = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			error = 1;
	i = 1;
	while (map[i])
	{
		if ((map[i][0] != '1') || map[i][ft_strlen(map[i]) - 1] != '1')
			error = 1;
		i++;
	}
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			error = 1;
	return (error);
}

static int	is_rect_map(char **map)
{
	size_t	len;
	int		i;
	int		error;

	error = 0;
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			error = 1;
		i++;
	}
	return (error);
}

int	ft_check_map(t_Game *game)
{
	if (is_closed_map(game->map))
		return (ft_putstr_fd("Error\nThe map is not closed", 2), 1);
	else if (is_rect_map(game->map))
		return (ft_putstr_fd("Error\nThe map is not rectangular", 2), 1);
	else if (is_playable(game))
		return (1);
	return (0);
}
