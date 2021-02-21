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
	while (*s == c)
		s++;
	return (s);
}

static int			how_many(char const *s, char c)
{
	int co;
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

static void			word_maker(char const *s, char c, char **out, 
int n_of_words)
{
	const char	*walker;
	int			beg;

	walker = s;
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
	int			n_of_words;

	if (s == NULL)
		return (NULL);
	
	n_of_words = how_many(s, c);
	out = malloc((n_of_words + 1) * sizeof(char **));
	if (out == NULL)
		return (NULL);
	word_maker(s, c, out, n_of_words);
	return (out);
}
