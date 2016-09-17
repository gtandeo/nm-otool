/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:35:19 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 11:35:21 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s1, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	while (n)
	{
		str[i] = s1[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}
