/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:24:18 by vvarussa          #+#    #+#             */
/*   Updated: 2021/02/16 18:45:24 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size > (4294967295 / nmemb))
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * nmemb);
	return (p);
}
