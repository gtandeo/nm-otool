/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 03:25:19 by gtandeo           #+#    #+#             */
/*   Updated: 2014/04/18 03:53:07 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)b;
	if (len > 0)
	{
		while (len)
		{
			str[i] = c;
			i++;
			len--;
		}
	}
	return (str);
}
