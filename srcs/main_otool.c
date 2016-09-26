/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:10:09 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/14 17:10:25 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

static void	print_file(char *file)
{
	ft_putstr(file);
	ft_putendl(":\n(__TEXT,__text) section");
	return ;
}

static void	handle_arch(t_otool *otool, size_t size)
{
	int					ret;
	uint32_t			ncmds;
	struct load_command	*lc;

	ret = 0;
	ncmds = ((struct mach_header*)otool->ptr)->ncmds;
	lc = (void*)(otool->ptr) + size;
	while (ncmds-- > 0)
	{
		if (lc->cmd == LC_SEGMENT)
			otool_32(otool, (void*)lc + sizeof(struct segment_command),
				((struct segment_command*)lc)->nsects);
		if (lc->cmd == LC_SEGMENT_64)
			otool_64(otool, (void*)lc + sizeof(struct segment_command_64),
				((struct segment_command_64*)lc)->nsects);
		lc = (void*)lc + lc->cmdsize;
	}
}

static void	handle_fat(t_otool *s, uint32_t nfat_arch)
{
	struct fat_arch			*arch;
	struct mach_header		*mach;
	struct fat_header		*header;

	header = (struct fat_header *)(s->ptr);
	nfat_arch = swap_int(header->nfat_arch);
	arch = (void*)(header + 1);
	while (nfat_arch--)
	{
		mach = (void*)((void*)header + swap_int(arch->offset));
		if (mach->magic == MH_MAGIC_64 && mach->cputype == CPU_TYPE_X86_64)
		{
			s->ptr = (void*)header + swap_int(arch->offset);
			if (__POINTER_WIDTH__ == 64)
				break ;
		}
		if (mach->magic == MH_MAGIC && mach->cputype == CPU_TYPE_X86)
		{
			s->ptr = (void*)header + swap_int(arch->offset);
			if (__POINTER_WIDTH__ == 32)
				break ;
		}
		arch = arch + 1;
	}
	otool(s);
}

void		otool(t_otool *s)
{
	s->magic = *(uint32_t*)s->ptr;
	if (s->magic == MH_MAGIC)
		handle_arch(s, sizeof(struct mach_header));
	else if (s->magic == MH_MAGIC_64)
		handle_arch(s, sizeof(struct mach_header_64));
	else if (s->magic == FAT_CIGAM)
		handle_fat(s, 0);
}

int			main(int ac, char **av)
{
	int			i;
	t_otool		*s;

	i = 0;
	if (ac < 2)
		return (argerror("ft_otool"));
	while (++i < ac)
	{
		if ((s = (t_otool *)init_struct(av[i])) == NULL)
			return (-1);
		print_file(av[i]);
		otool(s);
		delete_struct(s);
	}
	return (0);
}
