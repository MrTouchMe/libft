/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 06:06:25 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/20 19:39:08 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

// int	main(void)
// {
// 	int	fd;

// 	fd = 1;
// 	ft_putnbr_fd(0, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(1000043, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(-1000043, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(2147483647, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(-2147483648, fd);
// 	ft_putchar_fd('\n', fd);
// 	return (0);
// }
