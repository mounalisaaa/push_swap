/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:51:45 by melyaaco          #+#    #+#             */
/*   Updated: 2023/11/16 18:43:16 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*ans;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if (!i)
		return (NULL);
	ans = malloc(sizeof(char) * i + 1);
	if (!ans)
		return (0);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

int	line_size(t_list *lst)
{
	int	i;
	int	ans;

	ans = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i] && lst->content[i] != '\n')
		{
			i++;
			ans++;
		}
		if (lst->content[i] == '\n')
			ans++;
		lst = lst->next;
	}
	return (ans);
}

void	ft_set_new(t_list **lst, t_list *curr)
{
	char	*new;
	t_list	*node;

	if (!(ft_strchr(curr->content, '\n')))
	{
		*lst = NULL;
		return ;
	}
	new = ft_strdup(ft_strchr(curr->content, '\n') + 1);
	if (!new)
	{
		*lst = NULL;
		return ;
	}
	node = malloc(sizeof(t_list));
	if (!node)
	{
		*lst = NULL;
		return ;
	}
	node->next = NULL;
	node->content = new;
	*lst = node;
}

void	ft_clear(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	if (!(*lst))
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		if (!next)
			ft_set_new(lst, curr);
		free(curr->content);
		free(curr);
		curr = next;
	}
}

char	*ft_line(t_list **lst)
{
	t_list	*curr;
	char	*line;
	int		i;
	int		j;

	if (!lst || !(*lst))
		return (NULL);
	j = 0;
	curr = *lst;
	line = malloc(sizeof(char) * (line_size(curr) + 1));
	if (!line)
		return (NULL);
	while (curr)
	{
		i = 0;
		while (curr->content[i] && curr->content[i] != '\n')
			line[j++] = curr->content[i++];
		if (curr->content[i] == '\n')
			line[j++] = '\n';
		curr = curr->next;
	}
	line[j] = '\0';
	ft_clear(lst);
	return (line);
}
