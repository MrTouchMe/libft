/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:36:15 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/21 00:55:33 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	word_count(const char *s, const char *set)
{
	size_t count = 0;
	int in_word = 0;

	while (*s)
	{
		if (!is_in_set(*s, set))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*strndup(const char *src, size_t n)
{
	char	*dest = (char *)malloc(n + 1);

	if (dest)
	{
		for (size_t i = 0; i < n; i++)
		{
			dest[i] = src[i];
		}
		dest[n] = '\0';
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	size_t count = word_count(s, &c);
	char **result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	size_t i = 0;
	while (*s)
	{
		if (!is_in_set(*s, &c))
		{
			size_t len = 0;
			while (s[len] && !is_in_set(s[len], &c))
				len++;
			result[i] = strndup(s, len);
			if (!result[i])
				return (NULL);
			i++;
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
