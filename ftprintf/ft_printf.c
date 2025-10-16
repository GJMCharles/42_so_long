/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:21:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/06/30 06:28:01 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_data(char *data)
{
	size_t	len;

	len = ft_strlen(data);
	ft_putstr_fd(data, 1);
	free(data);
	return (len);
}

size_t	fetch_from_signs(size_t *index, const char *str, va_list args)
{
	size_t		i;

	i = 0;
	*index += 1;
	if (str[i] == 'c')
		return (ft_putchar_fd((int)va_arg(args, int), 1));
	else if (str[i] == '%')
		return (ft_putchar_fd((int) '%', 1));
	else if (str[i] == 's')
		return (print_string(va_arg(args, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (print_integer(va_arg(args, int), 0));
	else if (str[i] == 'u')
		return (print_integer(va_arg(args, int), 1));
	else if (str[i] == 'p')
		return (print_pointer(va_arg(args, unsigned long int)));
	else if (str[i] == 'x')
		return (print_hexadecimal(va_arg(args, unsigned long int), 0));
	else if (str[i] == 'X')
		return (print_hexadecimal(va_arg(args, unsigned long int), 1));
	return (0);
}

size_t	printf_buffer(const char *str, size_t len, va_list args)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (i < len && str[i])
	{
		if (str[i] == '%')
			size += fetch_from_signs(&i, str + i + 1, args);
		else
			size += ft_putchar_fd(str[i], 1);
		i += 1;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		size;

	if (!str)
		return (-1);
	va_start(args, str);
	size = printf_buffer(str, ft_strlen(str), args);
	va_end(args);
	return (size);
}
