/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 12:39:20 by gtandeo           #+#    #+#             */
/*   Updated: 2014/09/24 12:39:23 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				lenstr(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			i++;
			str++;
		}
	}
	return (i);
}

static int		find_nl(char *str)
{
	char	*bak;

	bak = str;
	if (str)
	{
		while (*str)
		{
			if (*str == EOF)
				return (str - bak - 1);
			if (*str++ == '\n')
				return (str - bak - 1);
		}
	}
	return (-1);
}

static char		*get_next_nl(char **str)
{
	int		pos;
	int		len;
	char	*ret;
	char	*bak;

	if ((pos = find_nl(*str)) == -1)
		return (NULL);
	if (!(ret = (char *)malloc((pos + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	while ((ret - bak) < pos)
		*ret++ = *((*str)++);
	*ret = 0;
	len = lenstr(*str);
	if (!(ret = (char *)malloc((lenstr(*str) + 1) * sizeof(*ret))))
		return (NULL);
	while (**str)
		*ret++ = *(++(*str));
	free(*str - len - pos);
	*str = ret - len;
	return (bak);
}

static char		*concat_string(char *old, char *buf, int n)
{
	char	*ret;
	char	*bak;

	if (!(ret = (char *)malloc((lenstr(old) + n + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	if (old)
		while (*old)
			*ret++ = *old++;
	*(ret + n) = 0;
	free(old - (ret - bak));
	while (n--)
		*(ret + n) = buf[n];
	return (bak);
}

int				get_next_line(int fd, char **line)
{
	char			*ret;
	int				nb_read;
	static char		*old;
	char			buf[BUFF_SIZE];

	while (!(ret = get_next_nl(&old)))
	{
		nb_read = read(fd, buf, BUFF_SIZE);
		if (!nb_read)
		{
			ret = old;
			*line = ret;
			return (0);
		}
		else if (nb_read == -1)
		{
			**line = '\0';
			return (-1);
		}
		old = concat_string(old, buf, nb_read);
	}
	*line = ret;
	return (1);
}
