/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:36:15 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/23 04:07:01 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to count words
static int  count_words(char const *s, char c)
{
    size_t  words_count;
    size_t  in_word;
    size_t  i;

    words_count = 0;
    in_word = 0;
    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            if (!in_word)
            {
                words_count++;
                in_word++;
            }
            else
            {
                in_word = 0;
            }
            s++;
        }
    }
    return (words_count);
}

// function to split words
static int split_words(char **result, const char *s, char c)
{
   size_t word = 0;
    size_t start_cur = 0;
    size_t str_length = strlen(s);

    while (start_cur < str_length)
    {
        while (s[start_cur] == c)
            start_cur++;
        size_t end_cur = start_cur;
        while (s[end_cur] && s[end_cur] != c)
            end_cur++;

        if (end_cur > start_cur)
        {
            size_t word_length = end_cur - start_cur;
            result[word] = (char *)malloc(word_length + 1);
            if (!result[word])
            {
                while (word > 0)
                    free(result[--word]);
                return 0;
            }
            strncpy(result[word], s + start_cur, word_length);
            result[word][word_length] = '\0';
            word++;
        }
        start_cur = end_cur + 1;
    }
    result[word] = NULL;
    return 1;
}

// main split function
char    **ft_split(char const *s, char c)
{
    char    **result;

    if (!s)
        return (NULL);
    result = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!result)
        return (NULL);
    if (!split_words(result, s, c))
    {
        free(result);
        return (NULL);
    }
    return (result);
}

