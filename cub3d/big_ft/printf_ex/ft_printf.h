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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>

int		ft_printf(int fd, const char *s, ...);
void	ft_putstr(char *string, char *s, int *idx);
void	ft_putnbr(char *string, long nb, int *idx);
void	ft_fillstr(char *string, char c, int *idx);
void	ft_hexaprintl(char *string, unsigned int nb, int *idx);
void	ft_hexaprintu(char *string, unsigned int nb, int *idx);
void	ft_putnbru(char *string, unsigned int nb, int *idx);
void	print_adresse(char *string, unsigned long long int c, int *idx);

#endif
