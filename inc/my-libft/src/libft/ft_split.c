/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:53:02 by nraymond          #+#    #+#             */
/*   Updated: 2023/11/18 13:50:30 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	**free_tab(char **s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		free(s[index]);
		index++;
	}
	free(s);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	size_t	index;
	int		words;

	index = 0;
	words = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		while (s[index] != c && s[index])
			index++;
		if ((s[index] == c) || (index == ft_strlen(s) && s[index - 1] != c))
			words += 1;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		k;
	int		start;
	char	**new;

	start = 0;
	k = 0;
	index = 0;
	new = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!(new))
		return (NULL);
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		start = index;
		if (!(s[index]))
			break ;
		while (s[index] != c && s[index])
			index++;
		new[k++] = ft_substr(s, start, index - start);
		if (!(new[k - 1]))
			return (free_tab(new));
	}
	return (new[k] = ((char *) NULL), new);
}
