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

static char	*get_hex(unsigned long int nb, unsigned short base, int uppercase)
{
	char	*ch;
	char	*prev;
	char	*data;

	ch = (char *) ft_calloc(2, sizeof(char));
	if (nb >= base)
	{
		prev = get_hex(nb / base, base, uppercase);
		if (uppercase)
			ch[0] = BASE_UPPER_X[nb % base];
		else
			ch[0] = BASE_LOWER_X[nb % base];
		data = ft_strjoin(prev, ch);
		free(prev);
		free(ch);
	}
	else
	{
		if (uppercase)
			ch[0] = BASE_UPPER_X[nb];
		else
			ch[0] = BASE_LOWER_X[nb];
		data = ch;
	}
	return (data);
}

size_t	print_pointer(unsigned long int nb)
{
	char	*data;
	char	*tmp;

	if (!nb)
		data = ft_strdup("(nil)");
	else
	{
		tmp = get_hex(nb, 16, 0);
		data = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (print_data(data));
}

size_t	print_hexadecimal(unsigned long int nb, int uppercase)
{
	char	*data;

	data = get_hex((unsigned int) nb, 16, uppercase);
	if (!data)
		return (0);
	return (print_data(data));
}
