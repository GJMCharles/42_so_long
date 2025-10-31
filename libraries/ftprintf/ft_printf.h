/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:01:06 by grcharle          #+#    #+#             */
/*   Updated: 2025/07/21 23:07:35 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "../libft/libft.h"

# define BASE_LOWER_X "0123456789abcdef"
# define BASE_UPPER_X "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
size_t	printf_buffer(const char *str, size_t len, va_list args);
size_t	fetch_from_signs(size_t *index, const char *str, va_list args);
size_t	print_data(char *data);
size_t	print_char(int ch);
size_t	print_string(const char *str);
size_t	print_integer(int nb, short int abs);
size_t	print_pointer(unsigned long int nb);
size_t	print_hexadecimal(unsigned long int nb, int uppercase);

#endif // FT_PRINTF_H
