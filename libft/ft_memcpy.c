/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 03:32:28 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/18 06:36:08 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*desti;

	source = (unsigned char *)src;
	desti = (unsigned char *)dst;
	if (n > 0)
	{
		while (n--)
			*desti++ = *source++;
	}
	return (dst);
}
