/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:22:13 by nraymond          #+#    #+#             */
/*   Updated: 2024/01/29 23:05:13 by bookoodoy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*check_last_empty(t_list **head, char **buffer, char **line, int len)
{
	char	*nl;

	if ((!*head))
		return (free_all(head, buffer, line), NULL);
	else
	{
		nl = extract_line(head, buffer, len);
		if (buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		if (*line)
			free(*line);
		return (nl);
	}
}

int	lst_add_last(t_list **head, char *new_data)
{
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->val = ft_strdup(new_data);
	if (!new_node->val)
	{
		free(new_node->val);
		return (free(new_node), 0);
	}
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return (1);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new_node;
	return (1);
}

int	get_end_line(t_list **head, char **buffer)
{
	t_list	*current;
	int		i;

	if (!*head)
	{
		if (!*buffer)
			return (-1);
		else if (!lst_add_last(head, *buffer))
			return (1);
	}
	i = 0;
	current = *head;
	while (current->next)
		current = current->next;
	while (current->val[i])
	{
		if (current->val[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*extract_line(t_list **head, char **buffer, int len)
{
	char	*line;
	t_list	*current;

	if (!*buffer)
		*buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = malloc(sizeof(char) * (BUFFER_SIZE * (len + 1)) + 1);
	if (!line || !*head || !*buffer)
		return (free_all(head, buffer, &line), NULL);
	line[0] = 0;
	current = *head;
	while (current)
	{
		if (current->val)
			add_last_char(line, current->val, *buffer);
		current = current->next;
	}
	if (!line[0])
		return (free_all(head, buffer, &line), NULL);
	return (free_all(head, NULL, NULL), line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			readc;
	int			i;
	t_list		*head;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (free_all(NULL, &(buffer[fd]), NULL), NULL);
	i = 1;
	head = NULL;
	while (get_end_line(&head, &buffer[fd]) == -1 && i++)
	{
		line = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!line)
			return (free_all(&head, &buffer[fd], NULL), NULL);
		readc = read(fd, line, BUFFER_SIZE);
		if (readc >= 0)
			line[readc] = 0;
		if (readc <= 0)
			return (check_last_empty(&head, &buffer[fd], &line, i));
		if (!lst_add_last(&head, line))
			return (free_all(&head, &buffer[fd], &line), NULL);
		free(line);
	}
	return (extract_line(&head, &buffer[fd], i));
}

/*
int	main(int argc, char **argv)
{
	if (argc > 1 && argc < 5)
	{
		int fd = open(argv[1], O_RDONLY);
		int fd2 = open(argv[2], O_RDONLY);
		int fd3 = open(argv[3], O_RDONLY);
		char	*line = get_next_line(fd);
		char	*line2 = get_next_line(fd2);
		char	*line3 = get_next_line(fd3);
		int	i = 0;
		int	k = 0;
		int	j = 0;
		while (line || line2 || line3)
		{
			printf("Line %i, first file = %s", i++, line);
			printf("Line %i, secnd file = %s", k++, line2);
			printf("Line %i, third file = %s", j++, line3);
			free(line);
			free(line2);
			free(line3);
			line = get_next_line(fd);
			line2 = get_next_line(fd2);
			line3 = get_next_line(fd3);
		}
		printf("Line %i, first file = %s", i, line);
		printf("Line %i, secnd file = %s", k, line);
		printf("Line %i, third file = %s", j, line3);
		free(line);
		free(line2);
		free(line3);
		close(fd);
		close(fd2);
		close(fd3);
	}
	return (0);
}
*/
