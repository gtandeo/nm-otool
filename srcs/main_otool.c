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

static void		*init_struct(char *file)
{
	t_otool		*s;
	struct stat	buf;

	s = NULL;
	if ((s = (t_otool *)malloc(sizeof(t_otool))) != NULL)
	{
		if ((s->fd = open(file, O_RDONLY)) < 0)
			return (openerror());
		if (fstat(s->fd, &buf) < 0)
			return (staterror());
		if ((s->ptr = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, s->fd, 0)) 
			== MAP_FAILED)
			return (mmaperror());
		s->buf = buf.st_size;
		s->magic = *(uint32_t*)(s->ptr);
		s->file_name = ft_strdup(file);
	}
	return (s);
}

static void		*delete_struct(t_otool *s)
{
	if (munmap(s->ptr, s->buf) < 0)
		return (munmaperror());
	close(s->fd);
	free(s->file_name);
	free(s);
	return (NULL);
}

void			otool(t_otool *s)
{
	if (s->magic == MH_MAGIC)
		write(1, "32\n", 3);//handle_32(otool);
	else if (s->magic == MH_MAGIC_64)
		write(1, "64\n", 3);//handle_64(otool);
	else if (s->magic == FAT_CIGAM)
		write(1, "fat\n", 4);//handle_fat(otool);
}

int				main(int ac, char **av)
{
	int			i;
	t_otool		*s;

	i = 0;
	if (ac < 2)
		return (argerror());
	while (++i < ac)
	{
		if ((s = (t_otool *)init_struct(av[i])) == NULL)
			return (-1);
		otool(s);
		delete_struct(s);
	}
	return (0);
}
