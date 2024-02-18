/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:45:25 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/18 18:45:28 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min(t_stack *b, t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->nb;
	while (a)
	{
		if (!(a->prev) || (a->nb < min))
		{
			min = a->nb;
			b->target = a;
			b->target_idx = i;
		}
		i++;
		a = a->next;
	}
}

t_stack	*get_cheapest(t_stack *b)
{
	int		cheap;
	t_stack	*cheapest;

	cheap = INT_MAX;
	cheapest = NULL;
	while (b)
	{
		if (b->cost < cheap)
		{
			cheapest = b;
			cheap = b->cost;
		}
		b = b->next;
	}
	return (cheapest);
}

void	get_idx(t_stack **a, int len)
{
	int		max;
	t_stack	*highest;
	t_stack	*curr;

	while (len-- > 0)
	{
		curr = *a;
		max = INT_MIN;
		highest = NULL;
		while (curr)
		{
			if (curr->nb == INT_MIN && curr->index == 0)
				curr->index = 1;
			if (curr->nb > max && curr->index == 0)
			{
				max = curr->nb;
				highest = curr;
				curr = *a;
			}
			else
				curr = curr->next;
		}
		if (highest != NULL)
			highest->index = len;
	}
}

void	cost(int i, t_stack *a, t_stack *b, int len_b)
{
	int	len_a;

	len_a = size(a);
	b->cost = i;
	if (!(b->above))
		b->cost = len_b - i;
	if (b->target->above)
		b->cost += b->target_idx;
	else
		b->cost += len_a - b->target_idx;
}
