/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:27:01 by grcharle          #+#    #+#             */
/*   Updated: 2025/07/31 17:27:04 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_recycle_dumpstr(char *dumpstr)
{
	char	*new_dumpstr;
	int		i;
	int		j;

	i = 0;
	while (dumpstr[i] && dumpstr[i] != '\n')
		i++;
	if (!dumpstr[i])
		return (free(dumpstr), dumpstr = 0, (void *)0);
	i++;
	new_dumpstr = malloc(sizeof(char) * (ft_strlen(dumpstr) - i + 1));
	if (!new_dumpstr)
		return (free(dumpstr), dumpstr = 0, (void *)0);
	j = 0;
	while (dumpstr[i])
		new_dumpstr[j++] = dumpstr[i++];
	new_dumpstr[j] = '\0';
	return (free(dumpstr), dumpstr = 0, new_dumpstr);
}

char	*ft_get_line(char *dumpstr)
{
	char	*line;
	int		i;

	i = 0;
	if (!dumpstr || !dumpstr[0])
		return (0);
	while (dumpstr[i] && dumpstr[i] != '\n')
		i++;
	if (dumpstr[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (dumpstr[i] && dumpstr[i] != '\n')
	{
		line[i] = dumpstr[i];
		i++;
	}
	if (dumpstr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *dumpstr)
{
	int		bytes_read;
	char	*buffer;

	if (!dumpstr)
		dumpstr = ft_strdup("");
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(dumpstr), dumpstr = 0, (void *)0);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), buffer = 0, free(dumpstr), dumpstr = 0,
				(void *)0);
		buffer[bytes_read] = '\0';
		dumpstr = ft_strjoin(dumpstr, buffer);
		if (!dumpstr)
			return (free(buffer), buffer = 0, (void *)0);
		if (ft_strchr(dumpstr, '\n'))
			break ;
	}
	return (free(buffer), buffer = 0, dumpstr);
}

char	*get_next_line(int fd)
{
	static char	*dumpstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (free(dumpstr), dumpstr = 0, (void *)0);
	dumpstr = ft_read_file(fd, dumpstr);
	if (!dumpstr)
		return (free(dumpstr), dumpstr = 0, (void *)0);
	line = ft_get_line(dumpstr);
	if (!line)
		return (free(dumpstr), dumpstr = 0, (void *)0);
	dumpstr = ft_recycle_dumpstr(dumpstr);
	return (line);
}
