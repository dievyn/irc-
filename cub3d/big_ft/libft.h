/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:52:01 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/30 10:52:03 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include "printf_ex/ft_printf.h"
# include "gnl/get_next_line.h"

char		*ft_itoa(int n);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			tab_len(char **tab);
int			free_tab(char **tab);
void		print_tab(char **tab);
char		*ft_strdup(char *str);
int			skip_space(char *str);
char		**copy_tab(char **tab);
int			ft_atoi(const char *nptr);
int			ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
long int	ft_atol(const char *nptr);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strncpy(char *dst, const char *src, int siz);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
size_t		ft_strlcpy(char *dst, const char *src, int siz);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t siz);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, int start, int len);
char		*ft_strnstr(const char *big, const char *little, size_t len);

#endif
