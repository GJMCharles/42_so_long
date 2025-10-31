/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:12:44 by grcharle          #+#    #+#             */
/*   Updated: 2025/10/29 22:12:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	char				content;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);

t_gnl_list	*ft_new_node(char buffer);
t_gnl_list	*ft_lst_last(t_gnl_list *node);
int			ft_line_in_lst(t_gnl_list **node, t_gnl_list **to_del);
char		*ft_lst_to_buffer(t_gnl_list **node, t_gnl_list **to_del);
void		ft_lst_add_back(t_gnl_list *new_node, t_gnl_list **current_node);
void		ft_del_lst(t_gnl_list **node, t_gnl_list **to_del);
void		buffer_to_lst(t_gnl_list **node, char *buffer);

#endif // GET_NEXT_LINE_H
