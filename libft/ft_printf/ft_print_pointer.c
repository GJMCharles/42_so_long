#include "../incs/ft_printf.h"

static void	ft_putnbr_base_pointer(unsigned long long int nbr, char *b, int *t)
{
	if (1)
	{
		if (nbr < 16)
			*t += ft_putchar_int(b[nbr], 1);
		else
		{
			ft_putnbr_base_pointer(nbr / 16, b, t);
			ft_putnbr_base_pointer(nbr % 16, b, t);
		}
	}
}

void	ft_getaddress(void *ptr, int *counter)
{
	uintptr_t	address;

	if (!ptr)
	{
		*counter += ft_putstr_int("(nil)", 1);
		return ;
	}
	address = (uintptr_t)ptr;
	*counter += ft_putstr_int("0x", 1);
	ft_putnbr_base_pointer(address, "0123456789abcdef", counter);
}
