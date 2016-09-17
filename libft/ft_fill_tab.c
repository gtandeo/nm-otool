/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 04:56:25 by gtandeo           #+#    #+#             */
/*   Updated: 2014/05/13 05:39:03 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_fill_tab(char **src, char **dest)
{
	int		i;
	int		j;

	i = 1;
	while (src[i])
	{
		j = 0;
		dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		while (src[i][j])
		{
			dest[i][j] = src[i][j];
			j++;
		}
		dest[i][j] = '\0';
		i++;
	}
	return (dest);
}
