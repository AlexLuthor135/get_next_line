/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:07:29 by alappas           #+#    #+#             */
/*   Updated: 2023/07/28 20:18:53 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	clean_list(t_list **list)

{
	int		i;
	int		j;
	t_list	*new_node;
	t_list	*last_node;
	char	*buf;

	if (list == NULL)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (buf == NULL || new_node == NULL)
		return ;
	while (last_node->str[i] && last_node->str[i++])
		buf[j++] = last_node->str[i];
	buf[j] = '\0';
	new_node->str = buf;
	new_node->next = NULL;
	dealloc(list, new_node, buf);
}

char	*ft_line(t_list *list)

{
	int		len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	len = str_len(list);
	next_str = malloc(len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_str_cpy(list, next_str);
	return (next_str);
}

void	add_str(t_list **list, char *buf)

{
	t_list	*new_node;
	t_list	*last_node;

	if (list == NULL)
		return ;
	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)

{
	int		char_read;
	char	*buf;

	while (!find_n(*list) || fd < 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add_str(list, buf);
	}
}

char	*get_next_line(int fd)

{
	static t_list	*list;
	char			*next_line;
	t_list			*param;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (list)
		{
			param = (list)->next;
			if ((list))
			{
				free((list)->str);
				free((list));
			}
			list = param;
		}
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_line(list);
	clean_list(&list);
	return (next_line);
}
