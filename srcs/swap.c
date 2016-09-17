/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:40:02 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 15:40:08 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

unsigned int	swap_int(unsigned int a)
{
	return ((a << 24) |
			((a << 8) & 0x00ff0000) |
			((a >> 8) & 0x0000ff00) |
			((unsigned int)(a >> 24)));
}