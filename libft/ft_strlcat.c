/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 08:56:18 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 11:58:10 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		t;

	d = dest;
	s = src;
	n = dsize;
	while (n-- != 0 && *d != '\0')
		d++;
	t = d - dest;
	n = dsize - t;
	if (n == 0)
		return (t + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (t + (s - src));
}
