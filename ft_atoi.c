/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:31:51 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 17:34:35 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	check_flag(int *flag)
{
	if (!*flag)
	{
		*flag = 1;
		return (0);
	}
	return (1);
}

int	check_sign(char *str, int *i, int *flag)
{
	int	sign;

	while (is_space(str[*i]))
		*i += 1;
	*flag = str[*i];
	if (!(check_flag(flag)))
		return (0);
	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	*flag = str[*i];
	if (!(check_flag(flag)))
		return (0);
	return (sign);
}

int	ft_atoi(char *str, int *flag)
{
	int		i;
	int		sign;
	size_t	result;

	i = 0;
	result = 0;
	sign = check_sign(str, &i, flag);
	if (!sign)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i++] - '0';
		if (result > 0x7fffffff)
		{
			if (sign == -1 && result == 2147483648)
				break ;
			*flag = 1;
			return (0);
		}
	}
	*flag = str[i];
	return (result * sign);
}
