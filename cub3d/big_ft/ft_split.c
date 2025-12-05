/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:30:56 by tdenis            #+#    #+#             */
/*   Updated: 2024/11/22 09:30:58 by tdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static char	**ft_free(char **tab, int j)
{
	while (j > 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

static int	ft_count(const char *s, char c)
{
	int	j;
	int	count;

	j = 0;
	if (s[j] == '\0' || s == NULL)
		return (0);
	count = 1;
	while (s[j] == c && s[j])
		j++;
	if (s[j] == '\0')
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
			count++;
		j++;
	}
	return (count);
}

static char	*handle_str(const char *s, char c, int *i)
{
	char	*str;
	char	*ptr;
	int		j;

	j = 0;
	while (s[*i + j] != c && s[*i + j] != '\0')
		j++;
	str = (char *) malloc(j + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		if (s[*i] == '\0')
			break ;
		str[j] = s[*i];
		(*i)++;
		j++;
	}
	str[j] = '\0';
	ptr = str;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		j;
	int		i;

	count = ft_count(s, c);
	tab = (char **) malloc((count + 1) * sizeof(char **));
	if (tab == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (j != count)
	{
		tab[j] = handle_str(s, c, &i);
		if (tab[j] == NULL)
			return (ft_free(tab, j));
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	tab[count] = NULL;
	return (tab);
}
