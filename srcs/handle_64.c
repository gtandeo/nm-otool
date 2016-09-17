/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:43:53 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 15:43:53 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void		get_output_64(struct symtab_command *sym, t_nm *nm)
{
	unsigned int		i;
	char				*stringtable;
	struct nlist_64		*array;
	t_list				*elm;
	t_list				*list;

	array = (void *)(nm->ptr) + sym->symoff;
	stringtable = (void *)(nm->ptr) + sym->stroff;
	i = -1;
	while (++i < sym->nsyms)
	{
		elm = lstnew(array[i].n_value, get_sect_64(nm, array[i]),
			stringtable + array[i].n_un.n_strx);
		list = lstadd(list, elm);
	}
	print_list((list = sort_list(list)), nm->addr_size);
	lstdel(list);
}

void			handle_64(t_nm *nm)
{
	unsigned int			ncmds;
	unsigned int			i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)(nm->ptr);
	ncmds = header->ncmds;
	lc = (void *)(nm->ptr) + sizeof(*header);
	section_numbers(nm, lc, header->ncmds);
	write(1, "", 0);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			nm->addr_size = 16;
			get_output_64(sym, nm);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
