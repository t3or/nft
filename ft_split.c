/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: yamouqin <yamouqin@student.1337.ma>        +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 04:10:10 by yamouqin          #+#    #+#             */
/*   Updated: 2026/10/30 04:10:10 by yamouqin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **words, size_t count)
{
	while (count)
		free(words[--count]);
	free(words);
}

static int	fill_words(char **words, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len)
		{
			words[i] = word_dup(s, len);
			if (!words[i])
			{
				free_words(words, i);
				return (0);
			}
			i++;
		}
		s += len;
	}
	words[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	count;

	count = word_count(s, c);
	words = malloc((count + 1) * sizeof(*words));
	if (!words)
		return (NULL);
	if (!fill_words(words, s, c))
		return (NULL);
	return (words);
}
