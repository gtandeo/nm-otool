/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 06:12:01 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 12:06:54 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lentrim(const char *s)
{
	size_t	length;

	length = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (length);
	while (*s)
	{
		length++;
		s++;
	}
	s--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		length--;
		s--;
	}
	return (length);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	int		n;

	if (!s)
		return (NULL);
	if (ft_lentrim(s) == ft_strlen(s))
		return (ft_strdup(s));
	str = NULL;
	str = (char*)ft_memalloc(ft_lentrim(s) + 1);
	n = ft_lentrim(s);
	if (str)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		ft_strncpy(str, s, n);
		str[n] = '\0';
	}
	return (str);
}
