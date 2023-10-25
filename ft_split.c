/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:36:15 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/25 07:44:12 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static void	split_free(char **s, int i )
{
	int	k;

	k = 0;
	if (!s)
		return ;
	while (s[k] && k < i)
		free(s[k++]);
	free(s);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

static void	write_word(char *dest, const char *src, char charset)
{
	int	i;

	i = 0;
	while (src[i] != charset && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	write_split(char **split, const char *s, char charset)
{
	int	i;
	int	word;
	int	size;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == charset)
			i++;
		if (!s[i])
			break ;
		size = ft_size_word(s, charset, i);
		split[word] = (char *) malloc (size + 1);
		if (!split[word])
		{
			split_free(split, word);
			return (0);
		}
		write_word (split[word], s + i, charset);
		i += ft_strlen (split[word]);
		word++;
	}
	split[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!write_split (res, s, c))
		return (NULL);
	res[word_count] = 0;
	return (res);
}
