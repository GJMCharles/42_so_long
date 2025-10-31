#include "../incs/ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *total)
{
	unsigned int	long_nbr;
	unsigned int	len_base;

	long_nbr = nbr;
	len_base = 16;
	if (1)
	{
		if (long_nbr < len_base)
			*total += ft_putchar_int(base[long_nbr], 1);
		else
		{
			ft_putnbr_base(long_nbr / len_base, base, total);
			ft_putnbr_base(long_nbr % len_base, base, total);
		}
	}
}
