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
