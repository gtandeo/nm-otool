/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:05:06 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 14:44:12 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char		get_sect(t_nm *nm, struct nlist array)
{
	char	m;

	m = array.n_type & N_TYPE;
	if (m == N_UNDF && array.n_value != 0)
		m = 'c';
	else if (m == N_UNDF || m == N_PBUD)
		m = 'u';
	else if (m == N_ABS)
		m = 'a';
	else if (m == N_INDR)
		m = 'i';
	else if (m == N_SECT && array.n_sect == nm->text_nsect)
		m = 't';
	else if (m == N_SECT && array.n_sect == nm->data_nsect)
		m = 'd';
	else if (m == N_SECT && array.n_sect == nm->bss_nsect)
		m = 'b';
	else if (m == N_SECT)
		m = 's';
	else
		m = '?';
	if ((array.n_type & N_EXT) && m != '?')
		m -= 32;
	return (m);
}

char		get_sect_64(t_nm *nm, struct nlist_64 array)
{
	char	m;

	m = array.n_type & N_TYPE;
	if (m == N_UNDF && array.n_value != 0)
		m = 'c';
	else if (m == N_UNDF || m == N_PBUD)
		m = 'u';
	else if (m == N_ABS)
		m = 'a';
	else if (m == N_INDR)
		m = 'i';
	else if (m == N_SECT && array.n_sect == nm->text_nsect)
		m = 't';
	else if (m == N_SECT && array.n_sect == nm->data_nsect)
		m = 'd';
	else if (m == N_SECT && array.n_sect == nm->bss_nsect)
		m = 'b';
	else if (m == N_SECT)
		m = 's';
	else
		m = '?';
	if ((array.n_type & N_EXT) && m != '?')
		m -= 32;
	return (m);
}

void		nm(t_nm *nm)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t*)(nm->ptr);
	if (magic_number == MH_MAGIC)
		handle_32(nm);
	else if (magic_number == MH_MAGIC_64)
		handle_64(nm);
	else if (magic_number == FAT_CIGAM)
		handle_fat(nm);
}

void		init_nm(t_nm *nm_s)
{
	nm_s->text_nsect = 0;
	nm_s->data_nsect = 0;
	nm_s->bss_nsect = 0;
	nm_s->nsect = 1;
	nm_s->addr_size = 16;
	nm_s->ptr = NULL;
}

int			main(int ac, char **av)
{
	int			fd;
	t_nm		nm_s;
	struct stat	buf;

	if (ac != 2)
		return (argerror("ft_nm"));
	init_nm(&nm_s);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return ((int)openerror());
	if (fstat(fd, &buf) < 0)
		return ((int)staterror());
	if ((nm_s.ptr = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
		return ((int)mmaperror());
	nm(&nm_s);
	if (munmap(nm_s.ptr, buf.st_size) < 0)
		return ((int)munmaperror());
	close(fd);
	return (0);
}
