/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:48:14 by tdenis            #+#    #+#             */
/*   Updated: 2025/04/08 11:48:16 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa(char *string, unsigned long long int nb, int *idx)
{
	if (nb >= 16)
	{
		ft_hexa(string, nb / 16, idx);
		ft_hexa(string, nb % 16, idx);
	}
	else if (nb < 10)
		ft_fillstr(string, nb + '0', idx);
	else if (nb > 9)
		ft_fillstr(string, nb + 87, idx);
}

void	print_adresse(char *string, unsigned long long int c, int *idx)
{
	char	*null;
	int		j;

	if (c == 0)
	{
		j = 0;
		null = ft_strdup("(nil)");
		while (null[j])
			ft_fillstr(string, null[j], idx);
		idx[1] += 5;
		free(null);
		return ;
	}
	ft_fillstr(string, '0', idx);
	ft_fillstr(string, 'x', idx);
	ft_hexa(string, c, idx);
	idx[1] += 2;
}

void	ft_hexaprintu(char *string, unsigned int nb, int *idx)
{
	if (nb >= 16)
	{
		ft_hexaprintu(string, nb / 16, idx);
		ft_hexaprintu(string, nb % 16, idx);
	}
	else if (nb < 10)
		ft_fillstr(string, nb + '0', idx);
	else if (nb > 9)
		ft_fillstr(string, nb + 55, idx);
}

void	ft_hexaprintl(char *string, unsigned int nb, int *idx)
{
	if (nb >= 16)
	{
		ft_hexaprintl(string, nb / 16, idx);
		ft_hexaprintl(string, nb % 16, idx);
	}
	else if (nb < 10)
		ft_fillstr(string, nb + '0', idx);
	else if (nb > 9)
		ft_fillstr(string, nb + 87, idx);
}
