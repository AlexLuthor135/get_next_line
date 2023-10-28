/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:06:09 by alappas           #+#    #+#             */
/*   Updated: 2023/07/04 19:54:54 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *list);
char	*ft_line(t_list *list);
int		find_n(t_list *list);
void	ft_str_cpy(t_list *list, char *string);
int		str_len(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	dealloc(t_list **list, t_list *new_node, char *buf);
char	*get_next_line(int fd);
void	clean_list(t_list **list);
void	add_str(t_list **list, char *buf);
void	ft_lstclear(t_list **list);
void	ft_lstdelone(t_list *list);

#endif