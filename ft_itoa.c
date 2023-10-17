/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:35:20 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/17 14:28:45 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(int numdigits, int sign, long int lin)
{
	char	*result;
	int		i;

	result = (char *)malloc((numdigits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numdigits] = '\0';
	i = numdigits - 1;
	while (lin > 0)
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

char	*ft_itoa(int n)
{
	int		sign;
	int		numdigits;
	long	lin;
	long	temp;

	sign = 1;
	numdigits = 0;
	lin = n;
	temp = lin;
	if (lin < 0)
	{
		sign = -1;
		lin = -lin;
		numdigits++;
	}
	while (temp >= 10)
	{
		numdigits++;
		temp /= 10;
	}
	numdigits++;
	return (ft_itoa2(numdigits, sign, lin));
}

// char    *ft_itoa2(int numdigits, int sign, long int lin)
// {
//     char    *result;
//     int     i;

//     result = (char *)malloc((numdigits + 1) * sizeof(char));
//     if (result == NULL)
//         return (NULL);
//     result[numdigits] = '\0';
//     i = numdigits - 1;
//     while (lin > 0)
//     {
//         result[i] = (lin % 10) + '0';
//         lin /= 10;
//         i--;
//     }
//     result[i] = lin + '0';
//     if (sign == -1)
//         result[0] = '-';
//     return (result);
// }

// char    *ft_itoa(int n)
// {
//     int     sign;
//     int     numdigits;
//     long    lin;
//     long    temp;

//     sign = 1;
//     numdigits = 0;
//     lin = n;
//     temp = lin;
//     if (lin < 0)
//     {
//         sign = -1;
//         lin = -lin;
//         numdigits++;
//     }
//     while (temp >= 10)
//     {
//         numdigits++;
//         temp /= 10;
//     }
//     numdigits++;
//     return (ft_itoa2(numdigits, sign, lin));
// }
