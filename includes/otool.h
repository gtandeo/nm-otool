/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:50:15 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/14 21:59:41 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct	s_otool
{
	int			buf;
	int			fd;
	uint32_t	magic;
	char		*file_name;
	void		*ptr;
}				t_otool;

void			*init_struct(char *file);
void			*delete_struct(t_otool *s);
unsigned int	swap_int(unsigned int a);
void			print_addr(uint64_t addr, int depth);
void			otool(t_otool *s);
int				otool_32(t_otool *otool, struct section *sect,
				uint32_t nsects);
int				otool_64(t_otool *otool, struct section_64 *sect,
				uint32_t nsects);
int				argerror(const char *name);
void			*openerror(void);
void			*staterror(void);
void			*mmaperror(void);
void			*munmaperror(void);

#endif
