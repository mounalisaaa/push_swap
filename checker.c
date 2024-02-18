/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:24:19 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/16 10:43:13 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	op_helper(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra (a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	op(char *line, t_stack **a, t_stack **b)
{
	if ((ft_strncmp(line, "sa\n", 3) == 0))
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(b, a, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb (b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr (a, b, 0);
	else if (!(op_helper(line, a, b)))
	{
		print("Error", 2);
		return (0);
	}
	return (1);
}

void	get_line(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			sort_check(*a, *b);
			free_stack(a);
			free_stack(b);
			return ;
		}
		if (!(op(line, a, b)))
		{
			free_stack(a);
			free_stack(b);
			free(line);
			return ;
		}
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack_b = NULL;
	stack = NULL;
	if (ac == 1)
		return (1);
	if (!(valid_args(ac, av, &stack)))
		return (1);
	get_line(&stack, &stack_b);
	return (0);
}
