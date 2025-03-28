/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:08:54 by hetya             #+#    #+#             */
/*   Updated: 2022/01/04 23:38:45 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * return the length of s (without conting the '\0')
*/
size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

/**
 * this function return the two string s1 s2 in a new string join
*/
char	*gnl_join(char *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	if (s2 == NULL)
		return (s1);
	join = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!join)
		return (NULL);
	if (s1 != NULL)
		while (s1[++j])
			join[i++] = s1[j];
	j = -1;
	while (s2[++j])
		join[i++] = s2[j];
	free(s1);
	join[i] = '\0';
	return (join);
}

/**
 * search the first occurence of c in the string s
*/
char	*gnl_strchr(char *s, int c)
{
	unsigned int	i;
	char			c1;

	i = 0;
	c1 = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c1)
		return ((char *) s + i);
	return (NULL);
}

/**
 * return a new string ptr from s. Thi new string begin a the index start of the
 * s1 string for length maximum of length
*/
char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	str_len;

	i = 0;
	if (!s)
		return (NULL);
	str_len = gnl_strlen(s);
	if (start >= str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
 * copy the memory pointed by dst in the src area for a lenght of n 
 * and it run when the 2 area overlapsing ieach other
*/
void	*gnl_memmove(void *dst, void *src, size_t len)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dst;

	i = len + 1;
	if (!dst && !src)
		return (NULL);
	ptr_src = (char *) src;
	ptr_dst = (char *) dst;
	if (dst > src)
		while (--i > 0)
			ptr_dst[i - 1] = ptr_src[i - 1];
	else
	{
		i = -1;
		while (++i < len)
			ptr_dst[i] = ptr_src[i];
	}
	return (dst);
}
