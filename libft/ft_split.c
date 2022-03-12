/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 04:28:26 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_alloc_string(char **dst, const char *src, char del)
{
	int		len;
	int		idx;

	len = 0;
	while (*src == del)
		src++;
	while (*src != del && *src != '\0')
	{
		src++;
		len++;
	}
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	src -= len;
	idx = 0;
	while (*(src + idx) != del && *(src + idx) != '\0')
	{
		*(*dst + idx) = *(src + idx);
		idx++;
	}
	*(*dst + idx) = '\0';
	return ((char *)(src + idx - 1));
}

static void	free_back(char **table, int idx)
{
	int	f_idx;

	f_idx = 0;
	while (f_idx < idx)
	{
		free(table[f_idx]);
		f_idx++;
	}
	free(table);
}

char	**ft_split(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		idx;

	idx = 0;
	word_count = ft_count_words(s, c);
	table = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (table == 0)
		return (0);
	while (idx < word_count)
	{
		s = ft_alloc_string(&table[idx], s, c);
		if (s == 0)
		{
			free_back(table, idx);
			return (0);
		}
		s++;
		idx++;
	}
	table[word_count] = 0;
	return (table);
}
