/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:48:05 by tdenis            #+#    #+#             */
/*   Updated: 2025/04/08 11:48:08 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(char *string, unsigned int nb, int *idx)
{
	if (nb < 10)
		ft_fillstr(string, nb + '0', idx);
	else if (nb > 9)
	{
		ft_putnbru(string, nb / 10, idx);
		ft_putnbru(string, nb % 10, idx);
	}
}

void	ft_putstr(char *string, char *s, int *idx)
{
	int		j;
	char	*null;

	j = 0;
	if (s == NULL)
	{
		null = ft_strdup("(null)");
		while (null[j])
			ft_fillstr(string, null[j], idx);
		free(null);
		return ;
	}
	while (s[j])
	{
		ft_fillstr(string, s[j], idx);
		j++;
	}
}

void	ft_putnbr(char *string, long nb, int *idx)
{
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		idx[1]++;
	}
	if (nb < 10)
		ft_fillstr(string, nb + '0', idx);
	else if (nb > 9)
	{
		ft_putnbr(string, nb / 10, idx);
		ft_putnbr(string, nb % 10, idx);
	}
}

void	ft_fillstr(char *string, char c, int *idx)
{
	string[idx[1]] = c;
	idx[1]++;
}
