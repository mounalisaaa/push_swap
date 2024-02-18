/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:54 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 17:21:15 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*a) || !(*a)->next)
		return ;
	temp1 = (*a)->next;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	(*a)->prev = temp;
	(*a)->next = NULL;
	temp1->prev = NULL ;
	*a = temp1;
	if (flag)
		print("ra", 1);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!(*b) || !(*b)->next)
		return ;
	temp1 = (*b)->next;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->next = *b;
	(*b)->prev = temp;
	(*b)->next = NULL;
	temp1->prev = NULL ;
	*b = temp1;
	if (flag)
		print("rb", 1);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag)
		print("rr", 1);
}

void	rra(t_stack **a, int flag)
{
	t_stack	*temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	(*a)->prev = temp;
	temp->next = *a;
	temp->prev = NULL;
	*a = temp;
	if (flag)
		print("rra", 1);
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	(*b)->prev = temp;
	temp->next = *b;
	temp->prev = NULL;
	*b = temp;
	if (flag)
		print("rrb", 1);
}
