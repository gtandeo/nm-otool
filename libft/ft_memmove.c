/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 04:11:13 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/20 11:46:06 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!(dst > src && src + len > dst))
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char *)dst + i) = *((char *)src + i);
		}
	}
	return (dst);
}
