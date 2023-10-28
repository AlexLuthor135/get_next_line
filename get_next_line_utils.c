/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:11:09 by alappas           #+#    #+#             */
/*   Updated: 2023/08/10 21:46:08 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_str_cpy(t_list *list, char *string)

{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				string[j++] = '\n';
				string[j] = '\0';
				return ;
			}
			string[j++] = list->str[i++];
		}
		list = list->next;
	}
	string[j] = '\0';
}

int	str_len(t_list *list)

{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *list)

{
	if (list != NULL)
	{
		while (list->next)
			list = list->next;
	}
	return (list);
}

int	find_n(t_list *list)

{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	dealloc(t_list **list, t_list *new_node, char *buf)

{
	t_list	*temp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (new_node->str[0])
		*list = new_node;
	else
	{
		free(buf);
		free(new_node);
	}
}
