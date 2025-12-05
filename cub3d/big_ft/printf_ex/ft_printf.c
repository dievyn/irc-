/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:42:24 by tdenis            #+#    #+#             */
/*   Updated: 2024/12/10 09:42:27 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	select_arg(char *string, const char *s, int *idx, va_list arg)
{
	if (ft_strnstr(&s[idx[0]], "%p", 2) != 0)
		print_adresse(string, (long long int)va_arg(arg, char *), idx);
	if (ft_strnstr(&s[idx[0]], "%s", 2) != 0)
		ft_putstr(string, (char *)va_arg(arg, char *), idx);
	else if (ft_strnstr(&s[idx[0]], "%d", 2) != 0)
		ft_putnbr(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%i", 2) != 0)
		ft_putnbr(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%u", 2) != 0)
		ft_putnbru(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%c", 2) != 0)
		ft_fillstr(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%X", 2) != 0)
		ft_hexaprintu(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%x", 2) != 0)
		ft_hexaprintl(string, (int)va_arg(arg, int), idx);
	else if (ft_strnstr(&s[idx[0]], "%%", 2) != 0)
		ft_fillstr(string, '%', idx);
	else
		return (0);
	return (1);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		idx[2];
	char	string[10000];
	va_list	arg;

	va_start (arg, s);
	idx[0] = 0;
	idx[1] = 0;
	while (s[idx[0]] != '\0')
	{
		if (select_arg(string, s, idx, arg) == 1)
			idx[0] += 2;
		else
		{
			ft_fillstr(string, s[idx[0]], idx);
			idx[0]++;
		}
	}
	string[idx[1]] = '\0';
	write(fd, &string, ft_strlen(string));
	va_end(arg);
	return (ft_strlen(string));
}
