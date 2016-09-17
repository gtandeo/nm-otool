/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:40:33 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/18 05:44:31 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = NULL;
	str = (char*)malloc(sizeof(char) * size);
	if (str)
		ft_bzero(str, size);
	else
		return (NULL);
	return (str);
}
