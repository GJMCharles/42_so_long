/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:10:27 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/31 10:10:28 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	verif_ext(char *str)
{
	char	*ext;
	int		i;

	ext = ".ber";
	str++;
	while (*str != '.')
	{
		str++;
	}
	i = ft_strncmp(str, ext, 5);
	return (i);
}
