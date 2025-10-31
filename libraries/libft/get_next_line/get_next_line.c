/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:12:32 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/29 22:12:34 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size_to_del(t_gnl_list **node, t_gnl_list **to_del)
{
	int			i;
	t_gnl_list	*current_node;

	i = 0;
	current_node = *node;
	while (current_node != *to_del && current_node)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

char	*ft_lst_to_buffer(t_gnl_list **node, t_gnl_list **to_del)
{
	int			i;
	char		*buffer;
	t_gnl_list	*current_node;

	if (!*node)
		return (NULL);
	i = ft_size_to_del(node, to_del);
	buffer = malloc (sizeof(char) * (i + 2));
	if (!buffer)
		return (NULL);
	current_node = *node;
	i = 0;
	while (current_node != *to_del && current_node)
	{
		buffer[i] = current_node->content;
		current_node = current_node->next;
		i++;
	}
	buffer[i] = current_node->content;
	i++;
	buffer[i] = '\0';
	return (buffer);
}

void	buffer_to_lst(t_gnl_list **node, char *buffer)
{
	t_gnl_list	*node_to_add;
	int			i;

	if (!buffer)
	{
		*node = NULL;
		return ;
	}
	i = 0;
	node_to_add = NULL;
	while (buffer[i])
	{
		node_to_add = ft_new_node(buffer[i]);
		ft_lst_add_back(node_to_add, node);
		i++;
	}
	free(buffer);
}

char	*ft_read_fail(char **buffer, t_gnl_list **node, t_gnl_list **to_del)
{
	free(*buffer);
	*to_del = ft_lst_last(*node);
	ft_del_lst(node, to_del);
	*node = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int					temp;
	char				*buffer;
	t_gnl_list			*to_del;
	static t_gnl_list	*node[1025];

	to_del = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = 1;
	while (temp > 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		temp = read(fd, buffer, BUFFER_SIZE);
		if (!buffer || temp < 0 || BUFFER_SIZE <= 0)
			return (ft_read_fail(&buffer, &(node[fd]), &to_del));
		buffer[temp] = '\0';
		buffer_to_lst(&(node[fd]), buffer);
		if ((ft_line_in_lst(&(node[fd]), &to_del)) || temp < BUFFER_SIZE)
			break ;
	}
	buffer = ft_lst_to_buffer(&(node[fd]), &to_del);
	ft_del_lst(&(node[fd]), &to_del);
	return (buffer);
}

// int		main(int argc, char *argv[])
// {
// 	(void) argc;
// 	(void) argv;
// 	int		fd1;
// 	int		fd2;
// 	char	*line1;
// 	char	*line2;
// 	int		i;

// 	fd1 = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[1], O_RDONLY);
// 	i = 0;
// 	line1 = "";
// 	while ((line1))
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (line1)
// 		{
// 			printf("[L1]: {%s", line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			printf("[L2]: {%s", line2);
// 			free(line2);
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
