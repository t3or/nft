/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: yamouqin <yamouqin@student.1337.ma>        +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/10/30 04:10:10 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
