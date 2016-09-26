/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:05:29 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/01 01:32:08 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct		s_nm
{
	unsigned int	text_nsect;
	unsigned int	data_nsect;
	unsigned int	bss_nsect;
	unsigned int	nsect;
	unsigned int	addr_size;
	char			*ptr;
}					t_nm;

typedef struct		s_data
{
	uint64_t		addr;
	char			sect;
	char			*name;
}					t_data;

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				nm(t_nm *nm);
t_list				*lstnew(const uint64_t addr, const char sect,
					const char *name);
t_list				*lstadd(t_list *lst, t_list *elm);
t_list				*sort_list(t_list *list);
void				print_list(t_list *list, unsigned int addr_size);
void				lstdel(t_list *lst);
void				print_addr(uint64_t addr, int depth);
void				handle_32(t_nm *nm);
void				handle_32_rev(t_nm *nm);
void				handle_64(t_nm *nm);
void				handle_64_rev(t_nm *nm);
void				handle_fat(t_nm *nm);
void				handle_fat_rev(t_nm *nm);
void				section_numbers(t_nm *nm_s, struct load_command *lc,
					uint32_t ncmds);
char				get_sect(t_nm *nm, struct nlist array);
char				get_sect_64(t_nm *nm, struct nlist_64 array);
unsigned int		swap_int(unsigned int a);
int					argerror(const char *name);
void				*openerror(void);
void				*staterror(void);
void				*mmaperror(void);
void				*munmaperror(void);

#endif
