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
	char		*ptr;
}				t_otool;

int				argerror(void);
void			*openerror(void);
void			*staterror(void);
void			*mmaperror(void);
void			*munmaperror(void);

#endif
