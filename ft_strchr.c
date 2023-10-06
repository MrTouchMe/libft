/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:34:47 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/07 00:10:34 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char*	ft_strchr(const char *s, int c)
{
	size_t i;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		return &s[i];
		i++;
	}
return(NULL);
}