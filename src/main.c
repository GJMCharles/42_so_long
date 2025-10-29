/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 03:06:52 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/29 13:38:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * 
int	fd;
if (argc < 2)
	exit(1);
fd = open(argv[1], O_RDONLY);
close(fd);
exit(MESSAGE).cav();
get_next_line()

STEP 01
READ FILE => GET CONTENT
VALIDATE CONTENT => AS MAP
CALCULATE MAP IN RELATION TO SCREEN

STEP 02
VERIFY TEXTURES FILES
LOAD TEXTURES FILES

STEP 03
CREATE WINDOW
ADD PROPERTIES TO OBJECTS LINKED TO TEXTURES
ADD TEXTURES TO MAP
*/
int	main(int argc, char *argv[])
{
	char	*map;

	if (argc != 2)
		error_exit("Invalid argument");
	map = extract_map(argv[1]);
	if (!map)
		error_exit("Invalid file extension [*.br] or forbidden format");
	return (EXIT_SUCCESS);
}
