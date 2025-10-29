/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:54:56 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/29 13:55:04 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*extract_map(const char *file_path)
{
	int	test;
	int	fd;

	test = ft_strncmp(\
		".br", \
		ft_substr(file_path, ft_strlen(file_path) - 3, 3), \
		3);
	if (test != 0)
		return ((char *)((void *)0));
	fd = open(file_path, O_RDONLY);
	close(fd);
	return ((char *)((void *)0));
}
