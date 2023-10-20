/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:35:20 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/21 00:58:12 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	int		numdigits;
	long	lin;
	char	*result;
	long	temp;

	sign = 1;
	numdigits = 0;
	lin = n;
	if (lin < 0)
	{
		sign = -1;
		lin = -lin;
		numdigits++;
	}
	temp = lin;
	while (temp >= 10)
	{
		numdigits++;
		temp /= 10;
	}
	numdigits++;
	result = (char *)malloc((numdigits + 2) * sizeof(char) - 1);
	if (result == NULL)
		return (NULL);
	result[numdigits] = '\0';
	numdigits--;
	while (lin >= 10)
	{
		result[numdigits] = (lin % 10) + '0';
		lin /= 10;
		numdigits--;
	}
	result[numdigits] = lin + '0';
	if (sign == -1)
		result[0] = '-';
	return (result);
}
