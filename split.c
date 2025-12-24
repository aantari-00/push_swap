/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 05:13:14 by aantari           #+#    #+#             */
/*   Updated: 2025/12/24 00:19:13 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	len;
	size_t	s;

	len = 0;
	i = 0;
	s = 1;
	while (str[i])
	{
		if (str[i] != c && s == 1)
		{
			len++;
			s = 0;
		}
		else if (str[i] == c)
			s = 1;
		i++;
	}
	return (len);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	ft_fill_words(char *s, char c, char **arr)
{
	size_t	i;
	size_t	start;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[word] = ft_substr(s, start, i - start);
			if (!arr[word])
			{
				ft_free_arr(arr);
				return ;
			}
			word++;
		}
	}
	arr[word] = NULL;
}

char	**ft_split(char *s, char c)
{
	size_t	words;
	char	**arr;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_fill_words(s, c, arr);
	return (arr);
}