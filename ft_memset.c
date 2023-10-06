/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:43 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/09/12 22:43:32 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void* ft_memset(void *b, int c, size_t len)
{
    unsigned char *p = (unsigned char* )b;
    unsigned char value = (unsigned char)c;

    while(len > 0)
    {
        *p = value;
        p++;
        len--;
    }
    return b;
}

