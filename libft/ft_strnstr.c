/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:34:56 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 11:35:07 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str;
	int		size;

	if (!*s2)
		return ((char *)s1);
	size = ft_strlen(s2);
	str = ft_strndup(s1, n);
	while (*str)
	{
		if (*str == *s2)
		{
			if (ft_strncmp(str, s2, size) == 0)
				return ((char *)s1);
		}
		str++;
		s1++;
	}
	return (NULL);
}
