/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: yamouqin <yamouqin@student.1337.ma>        +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/10/30 04:10:10 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
