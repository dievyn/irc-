/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:38:32 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/25 11:38:34 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reset_error(int *k, char *s, int siz)
{
	(*k) = 0;
	ft_bzero(s, siz);
	ft_sizestr("error", 0);
	f_read(0, "error", 0, 0);
}

int	ft_countline(const char *s, int k)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (k == 0)
		return (0);
	if (s[i] == '\n')
		n++;
	while (n != k && s[i] != '\0')
	{
		i++;
		if (s[i] == '\n')
			n++;
	}
	return (n);
}

int	ft_detect_line(const char *s, int k)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (k == 1)
		return (0);
	if (s[i] == '\n')
		n++;
	while (n != k && s[i] != '\0')
	{
		i++;
		if (s[i] == '\n')
			n++;
	}
	return (i + 1);
}
