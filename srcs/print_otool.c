/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_otool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:58:52 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/26 22:58:54 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

static void	set_sect_data(struct section_64 *data, struct section *sect,
	size_t size)
{
	ft_memcpy(data, sect, size);
	if (size == sizeof(struct section_64))
		return ;
	data->addr = sect->addr;
	data->size = sect->size;
	data->offset = sect->offset;
	data->align = sect->align;
	data->reloff = sect->reloff;
	data->nreloc = sect->nreloc;
	data->flags = sect->flags;
}

static void	print_section(t_otool *otool, struct section *sect, size_t size)
{
	void				*start;
	uint32_t			offset;
	uint32_t			i;
	uint8_t				byte_word;
	struct section_64	data;

	set_sect_data(&data, sect, size);
	start = (void*)otool->ptr + data.offset;
	offset = 0;
	while (offset < data.size)
	{
		print_addr((uint64_t)(data.addr + offset),
			(otool->magic == MH_MAGIC ? 8 : 16));
		i = 0 * (int)write(1, " ", 1);
		while (i < 16 * sizeof(char) && offset + i < data.size)
		{
			byte_word = *(uint8_t*)(start + offset + i);
			print_addr(byte_word, 2);
			write(1, " ", 1);
			i += sizeof(char);
		}
		write(1, "\n", 1);
		offset += i;
	}
}

int			otool_64(t_otool *otool, struct section_64 *sect, uint32_t nsects)
{
	while (nsects--)
	{
		if (ft_strcmp(sect->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(sect->segname, SEG_TEXT) == 0)
		{
			print_section(otool, (void*)sect, sizeof(*sect));
			return (1);
		}
		sect += 1;
	}
	return (0);
}

int			otool_32(t_otool *otool, struct section *sect, uint32_t nsects)
{
	while (nsects--)
	{
		if (ft_strcmp(sect->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(sect->segname, SEG_TEXT) == 0)
		{
			print_section(otool, (void*)sect, sizeof(*sect));
			return (1);
		}
		sect += 1;
	}
	return (0);
}
