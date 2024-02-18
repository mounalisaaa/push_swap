/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:50:33 by melyaaco          #+#    #+#             */
/*   Updated: 2024/01/19 15:35:14 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_addback(t_list **lst, char *buff)
{
	t_list	*node;
	t_list	*curr;

	curr = *lst;
	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = buff;
	node->next = NULL;
	if (!(*lst))
	{
		*lst = node;
		return (1);
	}
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	return (1);
}

char	*helper(t_list **lst, int fd)
{
	char			*buff;
	ssize_t			bytesread;

	while (1)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(buff);
			return (ft_line(lst));
		}
		buff[bytesread] = '\0';
		if (!(ft_addback(lst, buff)))
			return (NULL);
		if (ft_strchr(buff, '\n'))
			return (ft_line(lst));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;	

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 0xffffffff
		|| (read(fd, NULL, 0)) < 0)
		return (NULL);
	if (lst && ft_strchr(lst->content, '\n'))
		return (ft_line(&lst));
	return (helper(&lst, fd));
}
