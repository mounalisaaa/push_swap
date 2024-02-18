/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:08:28 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 16:34:01 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isabove(t_stack *head)
{
	int	i;
	int	mid;
	int	len;

	i = 0;
	len = size(head);
	mid = len / 2;
	while (head)
	{
		if (i <= mid)
			head->above = 1;
		else
			head->above = 0;
		i++;
		head = head->next;
	}
}

void	sorting(t_stack **a)
{
	t_stack	*small;
	t_stack	*temp;

	if (sorted(*a))
		return ;
	small = *a;
	temp = *a;
	isabove(*a);
	while (temp)
	{
		if (small->nb > temp->nb)
			small = temp;
		temp = temp->next;
	}
	if (small->above)
	{
		while (small != *a)
			ra(a, 1);
	}
	else
	{
		while (small != *a)
			rra(a, 1);
	}
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

int	get_num(char **str, t_stack **a)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	while (str[i])
	{
		k = ft_atoi(str[i], &flag);
		if (flag || check_dup(*a, k))
		{
			free_arr(str);
			free_stack(a);
			print("Error", 2);
			return (0);
		}
		ft_lstadd_back(a, k);
		i++;
	}
	return (1);
}
