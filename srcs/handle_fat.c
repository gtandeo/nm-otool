/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:29:22 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/02 12:29:25 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static int		check_arch_type(t_nm *nm_s, struct mach_header *header,
	struct fat_arch *arch)
{
	if (header->magic == MH_MAGIC_64 && swap_int(arch->cputype)
		== CPU_TYPE_X86_64)
	{
		nm_s->ptr = (void *)header;
		if (__POINTER_WIDTH__ == 64)
			return (1);
	}
	else if (header->magic == MH_MAGIC && swap_int(arch->cputype)
		== CPU_TYPE_X86)
	{
		nm_s->ptr = (void *)header;
		if (__POINTER_WIDTH__ == 32)
			return (2);
	}
	return (0);
}

void			handle_fat(t_nm *nm_s)
{
	uint32_t				i;
	struct mach_header		*header;
	struct fat_header		*fat;
	struct fat_arch			*arch;

	fat = (struct fat_header *)(nm_s->ptr);
	arch = (void *)(nm_s->ptr) + sizeof(struct fat_header);
	i = 0;
	while (i < swap_int(fat->nfat_arch))
	{
		header = (void *)(fat) + swap_int(arch->offset);
		if (check_arch_type(nm_s, header, arch))
			break ;
		arch = arch + 1;
		i++;
	}
	nm(nm_s);
}
