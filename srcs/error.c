/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:38:21 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 17:38:22 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int		argerror(const char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putendl(" FILE1 [FILE2 ...]");
	return (-1);
}

void	*openerror(void)
{
	write(2, "openerror\n", 10);
	return (NULL);
}

void	*staterror(void)
{
	write(2, "staterr\n", 8);
	return (NULL);
}

void	*mmaperror(void)
{
	write(2, "mmaperr\n", 8);
	return (NULL);
}

void	*munmaperror(void)
{
	write(2, "munmaperr\n", 10);
	return (NULL);
}
