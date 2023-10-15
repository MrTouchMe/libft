/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:35:20 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/16 01:30:15 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			sign;
	int			numdigits;
	long int	lin;

	sign = 1;
	numdigits = 0;
	lin = n;
	if (lin < 0)
	{
		sign = -1;
		lin = -lin;
		numdigits++;
	}
	long int temp = lin;
	while (temp >= 10)
	{
		numdigits++;
		temp /= 10;
	}
	numdigits++;
	char *result = (char *)malloc((numdigits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numdigits] = '\0';
	int i = numdigits - 1;
	while (lin >= 10)
	{
		result[i] = (lin % 10) + '0';
		lin /= 10;
		i--;
	}
	result[i] = lin + '0';
	if (sign == -1)
		result[0] = '-';
	return (result);
}
