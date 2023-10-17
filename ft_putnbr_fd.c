/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:06:25 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/17 20:15:24 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nn;
	int		power_of_ten;
	int		temp;

	nn = (long)n;
	if (nn == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	power_of_ten = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		power_of_ten *= 10;
	}
	while (power_of_ten > 0)
	{
		ft_putchar_fd('0' + n / power_of_ten, fd);
		n %= power_of_ten;
		power_of_ten /= 10;
	}
}
