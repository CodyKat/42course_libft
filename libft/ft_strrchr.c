/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:38 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/12 16:25:10 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;
	char	to_find;

	s_len = ft_strlen(s);
	to_find = c;
	if (to_find == '\0')
		return ((char *)s + s_len);
	while (s_len > 0)
	{
		if (*(s + s_len - 1) == to_find)
			return ((char *)(s + s_len - 1));
		s_len--;
	}
	return (0);
}
