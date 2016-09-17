/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:30:45 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/19 09:10:38 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	ptr;

	i = 0;
	j = 0;
	ptr = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			if (j == 0)
				ptr = i;
			j++;
		}
		else
			j = 0;
		i++;
		if (s2[j] == '\0')
			return ((char *)(s1 + ptr));
	}
	return (NULL);
}
