/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:39:58 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 15:39:59 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void	print_addr(uint64_t addr, int depth)
{
	if (depth == 0)
		return ;
	print_addr(addr >> 4, depth - 1);
	addr = addr & 0xF;
	if (addr < 10)
		addr += '0';
	else
		addr += 'a' - 10;
	write(1, &addr, 1);
}
