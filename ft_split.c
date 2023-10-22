/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:36:15 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/22 22:05:26 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to count words
static int	count_words(char const *s, char c)
{
	size_t	words_count = 0;
	size_t	in_word = 0;
	size_t	i = 0;
	while (*s)
	{
		if (*s != c)
			if (!in_word)
			{
				words_count++;
				in_word++;
			}
			else (in_word = 0);
			s++;
	}
	return (words_count);
}

// function to split words
static int	split_words(char **result, char const *s, char c)
{
	size_t	word = 0;
	size_t	start_cur = 0;
	size_t	end_cur = 0;
	while (s[end_cur])
	{
		if ( s[end_cur] == c || s[end_cur] == '\0')
		{
			start_cur = end_cur + 1;
		}
        if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == '\0'))
        {
            result[word] = malloc (sizeof (char *) * (end_cur - start_cur + 2));
            if (!result[word])
            {
                while (word-- /*word is greater than or equal to 0*/)
                    free (result[word]);
                return (0);
            }
            ft_strcpy (result[word], (s + start_cur), end_cur - start_cur +2);
        }
        end_cur++;
	}
    result[word] = 0;
	return(1);
}

// main split function
char	**ft_split(char const *s, char c)
{
	char	**result;
	if (!s)
		return (NULL);
	result = malloc (sizeof (char *) * (count_words)(s, c) + 1);
	if (!result)
		return (NULL);
	return (result);
}
