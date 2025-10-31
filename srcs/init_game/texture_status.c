/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:10:21 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:10:23 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*bis(void *ptr, char *p, int *w, int *h)
{
	return (mlx_xpm_file_to_image(ptr, p, w, h));
}

void	init_texture(t_Game *game)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	game->t = malloc(sizeof(t_Texture));
	if (!game->t)
	{
		free_game(game);
		return ;
	}
	game->t->c_d = bis(game->d.mlx, "./text/d_c.xpm", &w, &h);
	game->t->o_d = bis(game->d.mlx, "./text/d_o.xpm", &w, &h);
	game->t->gro = bis(game->d.mlx, "./text/tiles.xpm", &w, &h);
	game->t->wal = bis(game->d.mlx, "./text/wall.xpm", &w, &h);
	game->t->pla = bis(game->d.mlx, "./text/p1_s.xpm", &w, &h);
	game->t->col = bis(game->d.mlx, "./text/coll.xpm", &w, &h);
	game->t->w = 64;
	game->t->h = 64;
}

void	clear_image(t_Game *game)
{
	mlx_destroy_image(game->d.mlx, game->t->c_d);
	mlx_destroy_image(game->d.mlx, game->t->o_d);
	mlx_destroy_image(game->d.mlx, game->t->gro);
	mlx_destroy_image(game->d.mlx, game->t->wal);
	mlx_destroy_image(game->d.mlx, game->t->pla);
	mlx_destroy_image(game->d.mlx, game->t->col);
	free(game->t);
}
