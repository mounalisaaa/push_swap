/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:50:15 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 18:02:16 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rr(a, b, 1);
	while (*a != cheap->target)
		ra(a, 1);
	while (*b != cheap)
		rb(b, 1);
	pa(a, b, 1);
}

void	reverse(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rrr(a, b, 1);
	while (*a != cheap->target)
		rra(a, 1);
	while (*b != cheap)
		rrb(b, 1);
	pa(a, b, 1);
}

void	rotation(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->above && !(cheap->target->above))
	{
		while (*a != cheap->target)
			rra(a, 1);
		while (*b != cheap)
			rb(b, 1);
	}
	else
	{
		while (*a != cheap->target)
			ra(a, 1);
		while (*b != cheap)
			rrb(b, 1);
	}
	pa(a, b, 1);
}
