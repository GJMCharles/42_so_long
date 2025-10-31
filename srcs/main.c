/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:10:37 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:10:39 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
}

int	close_win(t_game *game)
{
	mlx_loop_end(game->d.mlx);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_loop_end(game->d.mlx);
	else if (keycode == 119)
		ft_move_w(game);
	else if (keycode == 97)
		ft_move_a(game);
	else if (keycode == 115)
		ft_move_s(game);
	else if (keycode == 100)
		ft_move_d(game);
	render_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_game		*game;

	(void) fd;
	game = ((t_game *)(void *)0);
	if (argc != 2)
		return (error_message("No map specified"), 0);
	if (verif_ext(argv[1]))
		return (error_message("Not a .ber file"), 0);
	fd = open(argv[1], O_RDONLY);
	game = init_struct(fd);
	close(fd);
	game->d.mlx = mlx_init();
	if (!game->d.mlx)
		return (free_game(game), 0);
	game->d.mlx_win = mlx_new_window(game->d.mlx, game->d.win.w, game->d.win.h, "SO_LONG");
	init_texture(game);
	render_map(game);
	mlx_hook(game->d.mlx_win, 17, 0, close_win, game);
	mlx_key_hook(game->d.mlx_win, key_hook, game);
	mlx_loop(game->d.mlx);
	mlx_destroy_window(game->d.mlx, game->d.mlx_win);
	if (game->player->w == 1)
		ft_printf("YOU WIN\n");
	free_game_2(game);
	return (0);
}
