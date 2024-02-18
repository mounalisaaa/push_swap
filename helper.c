/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:47:59 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/16 10:36:54 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, int data)
{
	t_stack	*last;
	t_stack	*new;

	last = ft_lstlast(*lst);
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(lst);
		return ;
	}
	new->nb = data;
	new->index = 0;
	new->next = NULL;
	new->prev = last;
	if (!last)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}

int	check_dup(t_stack *lst, int data)
{
	while (lst)
	{
		if (lst->nb == data)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	print(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	write(fd, "\n", 1);
}

int	valid_args(int ac, char **av, t_stack **stack)
{
	int		i;
	char	**str;

	i = 1;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str || !(*str))
		{
			free_arr(str);
			free_stack(stack);
			print("Error", 2);
			return (0);
		}
		if (!(get_num(str, stack)))
			return (0);
		free_arr(str);
		i++;
	}
	return (1);
}
