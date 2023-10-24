/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:36:15 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/24 03:08:33 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to free
// This is a helper function that frees the memory allocated for an array of strings.
// It takes two arguments: an array of strings (str) and the size of the array (size).
// It iterates through the array and frees each string and returns -1.
static void	split_free(const char **s)
{
	if (!s)
		return ;
	while (*s)
		free(*s++);
	free(s);
}

// function to count words
// This function counts the number of words in the input string str based on the delimiter character charset.
// It iterates through the string and counts words based on the presence of the delimiter.
// It returns the count of words found.
static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
		if (s[i] == c && s[++i] != c)
			words++;
	return (words);
}

// copy from input to dest
// This function is responsible for copying a word from the input string to a destination string.
// It takes three arguments: the destination string (dest), the source string (from), and the delimiter character charset.
// It copies characters from from to dest until it reaches the delimiter or the end of the string.


// splt strings into words and malloc
// This function splits the input string into words and allocates memory for each word.
// It takes three arguments: an array of strings (split), the input string (str), and the delimiter character charset.
// It iterates through the string, identifies words based on the delimiter,
// allocates memory for each word, and copies the word using the write_word function.


// main function
// It calculates the number of words in the input string using the count_words function.
// It then allocates memory for an array of strings (res) to store the split words.
// It calls the write_split function to populate the res array with the split words.
// The function returns this array of split words.
char	**ft_split(char const *s, char c)
{
	char **res;

	if (!s)
		return (NULL);
	if (!*s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	split(/*res*/, /*s*/, /*c*/);
	return (res);
}
