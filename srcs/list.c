/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:00:46 by gtandeo           #+#    #+#             */
/*   Updated: 2016/06/27 16:00:46 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void		print_list(t_list *list, unsigned int addr_size)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (((t_data *)tmp->data)->addr != 0)
			print_addr(((t_data *)tmp->data)->addr, addr_size);
		else if (addr_size == 16)
			ft_putstr("                ");
		else
			ft_putstr("        ");
		write(1, " ", 1);
		ft_putchar(((t_data *)tmp->data)->sect);
		write(1, " ", 1);
		ft_putendl(((t_data *)tmp->data)->name);
		tmp = tmp->next;
	}
	return ;
}

t_list		*sort_list(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_data	*tmp;

	tmp1 = lst;
	while (tmp1 && tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(((t_data *)tmp1->data)->name,
				((t_data *)tmp2->data)->name) > 0)
			{
				tmp = tmp1->data;
				tmp1->data = tmp2->data;
				tmp2->data = tmp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (lst);
}

void		lstdel(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		free(((t_data *)tmp->data)->name);
		free((t_data *)tmp->data);
		if (tmp->prev)
			free(tmp->prev);
		if (!tmp->next)
			free(tmp);
		tmp = tmp->next;
	}
	return ;
}

t_list		*lstnew(const uint64_t addr, const char sect, const char *name)
{
	t_list	*new;
	t_data	*data;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->addr = addr;
	data->sect = sect;
	data->name = ft_strdup((char*)name);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list		*lstadd(t_list *lst, t_list *elm)
{
	t_list	*tmp;

	tmp = lst;
	if (elm)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
		{
			elm->prev = tmp;
			tmp->next = elm;
		}
		else
			lst = elm;
	}
	return (lst);
}
