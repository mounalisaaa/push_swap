/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:41:53 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 17:08:55 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	int		min;
	int		max;
	t_stack	*curr;

	curr = *a;
	if (sorted(*a))
		return ;
	while (1)
	{
		min = curr->nb;
		max = curr->next->nb;
		if (min > max)
			swap(&min, &max);
		if (min == curr->nb && min > curr->next->next->nb)
			rra(a, 1);
		if (max == (*a)->next->nb)
			sa(a, 1);
		if ((*a)->next->next->nb > max)
			sa(a, 1);
		else if ((*a)->next->next->nb < max)
			ra(a, 1);
		curr = *a;
		if (sorted(curr))
			break ;
	}
}

int	find_min(t_stack *a)
{
	int		i;
	int		j;
	int		min;
	t_stack	*temp;

	i = 0;
	j = 1;
	temp = a;
	min = temp->nb;
	while (temp->next)
	{
		if (min > temp->next->nb)
		{
			min = temp->next->nb;
			i = j;
		}
		j++;
		temp = temp->next;
	}
	return (i);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	i;

	i = find_min(*a);
	if (i == 1)
		ra(a, 1);
	else if (i == 2)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (i == 3)
		rra(a, 1);
	pb(b, a, 1);
	sort_3(a);
	pa(a, b, 1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	i;

	i = find_min(*a);
	if (i == 1)
		ra(a, 1);
	else if (i == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (i == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (i == 4)
		rra(a, 1);
	pb(b, a, 1);
	sort_4(a, b);
	pa(a, b, 1);
}

void	small_sort(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		sa(a, 1);
	else if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
}
