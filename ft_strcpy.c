/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:23:10 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/09/11 21:43:10 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char*  ft_strcpy(char *dst, const char *src)
{
    if (dst == NULL || src == NULL)
    {
        return;
    }

    int i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
}