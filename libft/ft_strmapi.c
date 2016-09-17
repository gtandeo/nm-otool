/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:17:40 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 12:00:30 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (s && f)
	{
		str = ft_memalloc(ft_strlen(s) + 1);
		if (str)
		{
			while (*s)
			{
				str[i] = f((unsigned int)i, *s);
				s++;
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
