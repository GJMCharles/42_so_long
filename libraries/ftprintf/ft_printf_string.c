/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:21:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/07/21 23:09:45 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(int ch)
{
	ft_putchar_fd(ch, 1);
	return (1);
}

size_t	print_string(const char *str)
{
	char	*data;

	if (!str)
		data = ft_strdup("(null)");
	else
		data = ft_strdup(str);
	if (!data)
		return (0);
	return (print_data(data));
}
