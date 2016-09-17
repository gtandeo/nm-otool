/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:14:07 by gtandeo           #+#    #+#             */
/*   Updated: 2014/12/08 12:35:39 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(int c);
void	ft_putchar_fd(int c, int fd);
void	ft_putendl(const char *str);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_print_tab(char **tab);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(const char *s);
int		ft_strequ(const char *s1, const char *s2);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t dsize);
size_t	ft_strlen(const char *s);
size_t	ft_tablen(char **tab);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strrchr(const char *s, int c);
char	**ft_strsplit(const char *s, char c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strndup(const char *s1, size_t n);
void	ft_fill_str(char *src, char *dest);
char	**ft_fill_tab(char **src, char **dest);
int		get_next_line(int fd, char **line);

#endif
