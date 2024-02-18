/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:16:24 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 17:16:55 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	swap(&((*a)->nb), &((*a)->next->nb));
	if (flag)
		print("sa", 1);
}

void	sb(t_stack **b, int flag)
{
	if (!b || !(*b) ||!(*b)->next)
		return ;
	swap(&((*b)->nb), &((*b)->next->nb));
	if (flag)
		print("sb", 1);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		print("ss", 1);
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*temp;

	if (!b || !(*b))
		return ;
	temp = NULL;
	if ((*b)->next)
	{
		temp = (*b)->next;
		temp->prev = NULL;
	}
	if (!(*a))
	{
		*a = *b;
		(*a)->next = NULL;
		*b = temp;
		if (flag)
			print("pa", 1);
		return ;
	}
	(*a)->prev = *b;
	(*b)->next = (*a);
	*a = *b;
	*b = temp;
	if (flag)
		print("pa", 1);
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	t_stack	*temp;

	if (!a || !(*a))
		return ;
	temp = NULL;
	if ((*a)->next)
	{
		temp = (*a)->next;
		temp->prev = NULL;
	}
	if (!(*b))
	{
		*b = *a;
		(*b)->next = NULL;
		*a = temp;
		if (flag)
			print("pb", 1);
		return ;
	}
	(*b)->prev = *a;
	(*a)->next = (*b);
	*b = *a;
	*a = temp;
	if (flag)
		print("pb", 1);
}
