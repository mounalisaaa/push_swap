/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:25:49 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/18 18:43:09 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		pushed;
	t_stack	*curr;

	i = 0;
	pushed = 0;
	while (i < len && pushed < len / 2)
	{
		curr = *a;
		if (curr->index <= len / 2)
		{
			pb(b, a, 1);
			pushed++;
		}
		else
			ra(a, 1);
		i++;
	}
	while (len - pushed > 3)
	{
		pb(b, a, 1);
		pushed++;
	}
}

void	find_target(t_stack *b, t_stack *a)
{
	int		i;
	int		max;
	t_stack	*curr;

	i = 0;
	max = INT_MAX;
	curr = a;
	while (curr)
	{
		if (b->nb < curr->nb && curr->nb < max)
		{
			max = curr->nb;
			b->target = curr;
			b->target_idx = i;
		}
		curr = curr->next;
		i++;
	}
	if (max == INT_MAX)
		min(b, a);
}

void	init(t_stack **a, t_stack **b)
{
	int		i;
	int		len_b;
	t_stack	*curr;

	i = 0;
	curr = *b;
	len_b = size(*b);
	isabove(*a);
	isabove(*b);
	while (curr)
	{
		find_target(curr, *a);
		cost(i, *a, curr, len_b);
		curr = curr->next;
		i++;
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	if (cheap->above && cheap->target->above)
		rotate(a, b, cheap);
	else if (!(cheap->above) && !(cheap->target->above))
		reverse(a, b, cheap);
	else
		rotation(a, b, cheap);
}

void	big_sort(t_stack **a, t_stack **b, int len)
{
	get_idx(a, len);
	push_b(a, b, len);
	sort_3(a);
	while (*b)
	{
		init(a, b);
		push_to_a(a, b);
	}
	sorting(a);
}
