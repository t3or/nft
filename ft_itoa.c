/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: yamouqin <yamouqin@student.1337.ma>        +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/10/30 04:10:10 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(long long number)
{
	size_t	len;

	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	number;
	size_t		len;
	size_t		index;
	char		*text;

	number = (long long)n;
	len = number_len(number);
	text = malloc(len + 1);
	if (!text)
		return (NULL);
	index = len;
	text[index] = '\0';
	if (number < 0)
	{
		text[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		text[--index] = '0' + number % 10;
		number /= 10;
	}
	if (index == len)
		text[--index] = '0';
	return (text);
}
