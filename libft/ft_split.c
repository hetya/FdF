/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:22:58 by hetya             #+#    #+#             */
/*   Updated: 2022/03/04 16:27:38 by hetya            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * count the word(separated by the serator sep) in the string str
*/
static size_t	count_words(const char *str, char sep)
{
	size_t		count;
	size_t		i;
	int			in_word;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (str[i] == sep && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

/**
 * return the len of the word (start at *s and finish by the separator sep)
*/
static size_t	len_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

/**
 * return the len of seperator (if sep == / "///" : return 2) start at *s and
 * finish by an other char who is not a separator (sep)
*/
static size_t	len_sep(const char *str, char sep)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0' && str[i] == sep)
		i++;
	return (i);
}

/**
 * verif if all the malloc and free all the ptr if somthing goes wrong
*/
static char	**verif(char **ptr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	is_null;

	i = 0;
	is_null = 0;
	while (i < len)
	{
		if (ptr[i] == NULL)
		{
			j = -1;
			while (++j < len)
			{
				if (ptr[j] != NULL)
				{
					free(ptr[j]);
				}
			}
			is_null = 1;
		}
		i++;
	}
	if (is_null == 1)
		free(ptr);
	return (ptr);
}

/**
 * split as many string as there are "word" in between to separator separator
 * return a char ** contening all the string a termining with a NULL "word"
*/
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index_word;
	size_t	index;
	char	**ptr;

	i = 0;
	j = 0;
	index = 0;
	index_word = -1;
	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (++index_word < count_words(s, c))
	{
		i = len_sep(&s[index], c);
		index = index + i;
		j = len_words(&s[index], c);
		ptr[index_word] = ft_substr(s, index, j);
		index = index + j;
	}
	ptr[index_word] = NULL;
	return (verif(ptr, count_words(s, c)));
}
