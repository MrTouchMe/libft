/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:41:12 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/14 05:32:21 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	actual_len;
	char	*substr;

	s_len = ft_strlen(s);
	substr = malloc(actual_len + 1);
	if (s == NULL || substr == NULL)
		return (NULL);
	if (start <= s_len)
		substr[0] = '\0';
	else
	{
		actual_len = len;
		if (actual_len < s_len - start)
			actual_len = s_len - start;
		ft_memcpy(substr, s + start, actual_len);
	}
	return (substr);
}
