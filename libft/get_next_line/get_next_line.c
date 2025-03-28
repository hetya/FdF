/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:09:01 by hetya             #+#    #+#             */
/*   Updated: 2022/01/05 00:36:00 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * return 1 if there is a new line in the string and 0 if not
*/
static int	new_line_in(char *str)
{
	int		i;
	size_t	new_line;

	i = 0;
	new_line = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			new_line = 1;
		i++;
	}
	return (new_line);
}

/**
 * return the len of a line begin at *s and ending at a '\n' or '\0'
*/
static size_t	line_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == '\n')
		i++;
	return (i);
}

/**
 * free the pointer given in parameter and
 * return NULL
*/
static char	*free_ptr(char *ptr)
{
	if (ptr)
		free (ptr);
	return (NULL);
}

/**
 * return the new line created by the substr of ptr with the length of
 * line_len(ptr)
 * then move the next line at the front of buf and free ptr
*/
static char	*new_line(char *buf, char *ptr)
{
	char			*line;

	line = gnl_substr(ptr, 0, line_len(ptr));
	if (line == NULL)
		return (free_ptr(ptr));
	gnl_memmove(buf, gnl_strchr(buf, '\n') + 1,
		gnl_strlen(gnl_strchr(buf, '\n')));
	free(ptr);
	return (line);
}

/**
 * use a buffer of size BUFFER_SIZE to read a line and then return it
 * for each call of the fonction, it will return the next line until there is
 * no line left
*/
char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				size;

	ptr = NULL;
	if (fd < 0)
		return (NULL);
	if (buf[0] != '\0')
		ptr = gnl_join(ptr, buf);
	if (buf[0] != '\0' && !ptr)
		return (NULL);
	while (new_line_in(buf) == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (free_ptr(ptr));
		buf[size] = '\0';
		if (size == 0)
			return (ptr);
		ptr = gnl_join(ptr, buf);
		if (!ptr)
			return (NULL);
	}
	return (new_line(buf, ptr));
}
