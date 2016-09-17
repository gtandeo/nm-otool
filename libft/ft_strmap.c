/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:16:06 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 11:59:37 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
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
				str[i] = f(*s);
				s++;
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
