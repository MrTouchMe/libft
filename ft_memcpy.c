/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:34:34 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/09/14 22:06:00 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void * ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *dst_ptr = (unsigned char*)dst;
    const unsigned char *src_ptr = (const unsigned char*)src;
    size_t i;
    i = 0;
    
    while(i < n)
    {
        dst_ptr[i] = src_ptr[i];
        i++;
    }
    
    return dst;
}

// *dst_ptr = *src_ptr;
//         dst_ptr++;        
//         src_ptr++;
//         n--;