/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:12:02 by tdenis            #+#    #+#             */
/*   Updated: 2025/11/26 14:12:12 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*bitstring(unsigned char num)
{
	char	*str;
	int		count;
	int		save;

	save = num;
	count = 7;
	str = ft_calloc(9, sizeof (char *));
	while (count >= 0)
	{
		num = num << count;
		num = num >> 7;
		if ((num | 0) == 1)
			str[count] = '1';
		else
			str[count] = '0';
		count--;
		num = save;
	}
	return (str);
}

unsigned int	decrypt_colors(int *tab)
{
	unsigned int	result;
	char			*bitstr;
	int				i;
	int				j;

	i = 1;
	result = tab[0];
	while (i < 3)
	{
		j = 0;
		bitstr = bitstring(tab[i]);
		while (j <= 7)
		{
			result = result << 1;
			if (bitstr[j] == '1')
				result++;
			j++;
		}
		free(bitstr);
		i++;
	}
	return (result);
}
