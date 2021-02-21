/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:27:33 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/18 14:12:58 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char const	*skip_char(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static int			how_many(char const *s, char c)
{
	size_t co;
	const char *s2;

	co = 0;
	s2 = skip_char(s, c);
	if ((*s2 == '\0') | (*s == '\0'))
				return (0);
	if (*s == c)
		co--;
	if (*(s + ft_strlen(s) - 1) == c)
		co--;
	while (*s != '\0')
	{
		if (*s == c)
		{
			co++;
			s = skip_char(s, c);
		}
		else
			s++;
	}
	return (co + 1);
}

/*static void			create_words(
	char **words, char const *s, char c, size_t word_count)
{
	char *pointerator;

	s = skip_char(s, c);
	while (word_count--)
	{
		pointerator = ft_strchr(s, c);
		if (pointerator != NULL)
		{
			*words = ft_substr(s, 0, pointerator - s);
			s = skip_char(pointerator, c);
		}
		else
			*words = ft_substr(s, 0, ft_strlen(s) + 1);
		words++;
	}
	*words = NULL;
}*/

static void			word_maker(char const *s, char c, char **out, 
size_t n_of_words)
{
	const char	*walker;
	int			beg;

	walker = s;
	walker = skip_char(walker, c);
	while (n_of_words--)
	{
		walker = skip_char(walker, c);
		beg = walker - s;
		while (*walker != c)
			walker++;
		*out = ft_substr(s, beg, walker - s - beg);
		out++;
	}
	*out = NULL;
}

char				**ft_split(char const *s, char c)
{
	char		**out;
	size_t			n_of_words;

	if (s == NULL)
		return (NULL);
	
	n_of_words = how_many(s, c);
	out = malloc((n_of_words + 1) * sizeof(char **));
	if (out == NULL)
		return (NULL);
	word_maker(s, c, out, n_of_words);
	//create_words(out, s, c, n_of_words);
	return (out);
}
