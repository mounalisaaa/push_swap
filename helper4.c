/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:00:18 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/16 10:43:25 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_check(t_stack *a, t_stack *b)
{
	if (b)
	{
		print("KO", 1);
		return ;
	}
	while (a->next)
	{
		if (a->nb > a->next->nb)
		{
			print("KO", 1);
			return ;
		}
		a = a->next;
	}
	print("OK", 1);
}

void	swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		print("rrr", 1);
}

int	size(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}
