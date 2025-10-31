#include "../../incs/so_long.h"

int	is_cutted(char *tmpmap)
{
	int	i;
	int	is_space;
	int	is_before;
	int	is_after;

	i = 0;
	is_space = 0;
	is_before = 0;
	is_after = 0;
	while (tmpmap[i])
	{
		if (tmpmap[i] != '\n' && is_before == 0)
			is_before = 1;
		if (tmpmap[i + 1] && tmpmap[i] == '\n' && tmpmap[i + 1] == '\n'
			&& is_before == 1)
			is_space = 1;
		if (tmpmap[i] != '\n' && is_before == 1 && is_space == 1)
			is_after = 1;
		i++;
	}
	if (is_space == 1 && is_before == 1 && is_after == 1)
		return (1);
	return (0);
}

void	ft_parser(int fd, char ***map)
{
	char	*str;
	char	*buffer;

	str = get_next_line(fd);
	if (!str)
	{
		*map = NULL;
		return ;
	}
	buffer = NULL;
	while (str)
	{	
		buffer = ft_strjoin(buffer, str);
		free(str);
		str = get_next_line(fd);
	}
	if (is_cutted(buffer))
	{
		*map = NULL;
		free(buffer);
		return ;
	}
	*map = ft_split(buffer, '\n');
	free(buffer);
}
