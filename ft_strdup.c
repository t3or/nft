/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamouqin <yamouqin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/11/06 22:39:13 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, len + 1);
	return (copy);
}
