/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:22:46 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/07 00:02:14 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') ||( c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}