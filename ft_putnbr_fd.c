/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamouqin <yamouqin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/11/06 15:53:49 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_number(long long number, int fd)
{
	char	digit;

	if (number >= 10)
		write_number(number / 10, fd);
	digit = '0' + number % 10;
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;

	number = (long long)n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	write_number(number, fd);
}
