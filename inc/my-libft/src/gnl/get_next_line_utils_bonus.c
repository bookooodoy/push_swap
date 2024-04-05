/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:22:13 by nraymond          #+#    #+#             */
/*   Updated: 2024/04/05 09:55:24 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	add_last_char(char *dst, const char *src, char *buffer)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	if (!src)
		return ;
	while (dst[i])
		i++;
	while (src[k])
	{
		dst[i + k] = src[k];
		if (src[k] == '\n')
		{
			j = 0;
			dst[i + k + 1] = 0;
			while (src[++k] != 0)
				buffer[j++] = src[k];
			buffer[j] = 0;
			return ;
		}
		k++;
	}
	dst[i + k] = 0;
}

void	free_all(t_list **head, char **buffer, char **line)
{
	t_list	*current;
	t_list	*next;

	if (buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (line)
		free(*line);
	if (!head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		if (current->val)
			free(current->val);
		free(current);
		current = next;
	}
}
