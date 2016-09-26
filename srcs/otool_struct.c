/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 00:04:05 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/27 00:04:06 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void	*init_struct(char *file)
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
		if ((s->ptr = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE,
			s->fd, 0)) == MAP_FAILED)
			return (mmaperror());
		s->buf = buf.st_size;
		s->file_name = ft_strdup(file);
	}
	return (s);
}

void	*delete_struct(t_otool *s)
{
	if (munmap(s->ptr, s->buf) < 0)
		return (munmaperror());
	close(s->fd);
	free(s->file_name);
	free(s);
	return (NULL);
}
