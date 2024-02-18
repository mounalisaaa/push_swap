/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:39:52 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/16 09:35:45 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		len;
	t_stack	*stack;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack = NULL;
	stack_b = NULL;
	if (!(valid_args(ac, av, &stack)))
		return (1);
	if (sorted(stack))
	{
		free_stack(&stack);
		return (1);
	}
	len = size(stack);
	if (len <= 5 && len >= 2)
		small_sort(&stack, &stack_b, len);
	else
		big_sort(&stack, &stack_b, len);
	free_stack(&stack);
	free_stack(&stack_b);
	return (0);
}
