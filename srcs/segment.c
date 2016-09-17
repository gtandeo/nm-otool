/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:10:27 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/14 15:10:29 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	get_sections(t_nm *nm_s, uint32_t i, struct section *s, size_t size)
{
	while (i-- > 0)
	{
		if (ft_strcmp(s->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(s->segname, SEG_TEXT) == 0)
			nm_s->text_nsect = nm_s->nsect;
		else if (ft_strcmp(s->sectname, SECT_DATA) == 0 &&
			ft_strcmp(s->segname, SEG_DATA) == 0)
			nm_s->data_nsect = nm_s->nsect;
		else if (ft_strcmp(s->sectname, SECT_BSS) == 0 &&
			ft_strcmp(s->segname, SEG_DATA) == 0)
			nm_s->bss_nsect = nm_s->nsect;
		s = (void*)s + size;
		nm_s->nsect++;
	}
}

void		section_numbers(t_nm *nm_s, struct load_command *lc, uint32_t ncmds)
{
	if (lc == NULL)
		return ;
	while (ncmds-- > 0)
	{
		if (lc->cmd == LC_SEGMENT)
			get_sections(nm_s, ((struct segment_command*)lc)->nsects,
				(void*)lc + sizeof(struct segment_command),
				sizeof(struct section));
		if (lc->cmd == LC_SEGMENT_64)
			get_sections(nm_s, ((struct segment_command_64*)lc)->nsects,
				(void*)lc + sizeof(struct segment_command_64),
				sizeof(struct section_64));
		lc = (void*)lc + lc->cmdsize;
	}
}
