/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:38:00 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/29 13:38:09 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *message)
{
	char	error[6];

	error[0] = 'E';
	error[1] = 'r';
	error[2] = 'r';
	error[3] = 'o';
	error[4] = 'r';
	error[5] = '\0';
	ft_putendl_fd(error, 1);
	if (!message)
	{
		ft_putstr_fd("REASON: ", 1);
		ft_putendl_fd((char *) message, 1);
	}
	exit(EXIT_FAILURE);
}
