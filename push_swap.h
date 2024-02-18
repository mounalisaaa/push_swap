/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:39:49 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/18 18:46:34 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				above;
	int				cost;
	int				target_idx;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

/*helper 5*/
void	print(char *str, int fd);
int		check_dup(t_stack *lst, int data);
void	ft_lstadd_back(t_stack **lst, int data);
int		valid_args(int ac, char **av, t_stack **stack);

/*helper1 5*/
void	free_arr(char **arr);
void	sorting(t_stack **a);
void	isabove(t_stack *head);
void	free_stack(t_stack **stack);
int		get_num(char **str, t_stack **a);

/*helper2 */
void	min(t_stack *b, t_stack *a);
t_stack	*get_cheapest(t_stack *b);
void	get_idx(t_stack **a, int len);
void	cost(int i, t_stack *a, t_stack *b, int len_b);

/*helper3 3*/
void	rotate(t_stack **a, t_stack **b, t_stack *cheap);
void	reverse(t_stack **a, t_stack **b, t_stack *cheap);
void	rotation(t_stack **a, t_stack **b, t_stack *cheap);

/*helper4 5*/
void	swap(int *i, int *j);
int		size(t_stack *head);
int		sorted(t_stack *head);
void	sort_check(t_stack *a, t_stack *b);
void	rrr(t_stack **a, t_stack **b, int flag);

/*big_sort 5*/
t_stack	*get_cheapest(t_stack *a);

char	*get_next_line(int fd);
int		word_count(char *str, char c);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str, int *flag);

/*instructions*/
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);

void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **b, t_stack **a, int flag);

/*instructions1*/
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);

void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);

void	small_sort(t_stack **a, t_stack **b, int len);
void	sort_3(t_stack **a);
void	big_sort(t_stack **a, t_stack **b, int len);

#endif
