/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 04:45:18 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/18 06:29:02 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (*src && n > 0)
	{
		*tmp++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*tmp++ = '\0';
		--n;
	}
	return (dst);
}
