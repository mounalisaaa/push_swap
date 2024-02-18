/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:30 by melyaaco          #+#    #+#             */
/*   Updated: 2024/02/13 17:35:53 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

char	*alloc_word(char *s, char c, int *i)
{
	int		j;
	char	*word;

	j = 0;
	while (s[*i + j] && s[*i + j] != c)
		j++;
	word = (char *)malloc(sizeof(char) * (j + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		word[j++] = s[*i];
		*i += 1;
	}
	word[j] = '\0';
	return (word);
}

static char	**free_(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!arr)
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			arr[k++] = alloc_word((char *)s, c, &i);
			if (!arr[k - 1])
				return (free_(arr, k - 1));
		}
	}
	arr[k] = 0;
	return (arr);
}
