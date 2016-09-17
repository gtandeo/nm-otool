/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 00:24:19 by gtandeo           #+#    #+#             */
/*   Updated: 2014/12/07 14:28:35 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_spe(int c)
{
	char	*cs;
	int		i;

	cs = "\n\v\t\r\f ";
	i = 0;
	while (i < 6)
	{
		if (cs[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	int		r;
	int		neg;

	r = 0;
	neg = 1;
	if (!str)
		return (0);
	while (ft_spe(*str))
		str++;
	while ((*str == '+' || *str == '-') && neg == 1)
	{
		if (*str == '-' || *(str + 1) == '+')
		{
			neg = -1;
			if (*(str - 1) == '+')
				str--;
		}
		str++;
	}
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		r = r * 10 + (*str) - 48;
		str++;
	}
	return (r * neg);
}
