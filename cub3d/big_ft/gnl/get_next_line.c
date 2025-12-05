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

static int	check_valid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) == 0 && ft_isspace(str[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

static char	*smth_like_strcpy(char *dst, const char *src, size_t siz)
{
	unsigned long	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (i != siz && src[i] && src[i] != '\n' )
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	dst[siz + 1] = '\0';
	return (dst);
}

int	ft_sizestr(char *s, int error)
{
	static int	j;
	int			siz;

	siz = 0;
	while (s[j] && s[j] != '\n')
	{
		j++;
		siz++;
	}
	j++;
	if (error == 0)
		j = 0;
	return (siz);
}

int	f_read(int k, char *s, int fd, int error)
{
	int			nb_read;
	static int	i;

	if (error == 0)
	{
		i = 0;
		return (0);
	}
	nb_read = 1;
	while (ft_countline(s, k) != k && nb_read != 0)
	{
		nb_read = read(fd, &s[BUFFER_SIZE * i], BUFFER_SIZE);
		if (nb_read == -1 || check_valid_str(s) != 0)
			return (-1);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	s[99999999];
	char		*str;
	static int	k;
	int			siz;

	siz = 0;
	k++;
	if (f_read(k, s, fd, 1) == 1)
	{
		siz = ft_sizestr(s, 1);
		str = ft_calloc((siz + 2), sizeof(char));
		if (str == NULL)
			return (NULL);
		smth_like_strcpy(str, &s[ft_detect_line(s, k)], siz);
		if (str[0] == 0)
			return (free(str), NULL);
		return (str);
	}
	else
		reset_error(&k, s, BUFFER_SIZE * k);
	return (NULL);
}

////-////-////-////-////-////-////-////-////-////-////-////-////-////-////-////
/*
void	ft_putstr(char *str)
{
	int	i;

//	write (1, "//////////", 10);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main (void)
{
	int fd;
	int i = 0;
	char *str;

	fd = open("test3", O_RDONLY);
//	fd = 0;
	if (fd == -1)
		return (1);
	while (i < 400)
	{
		str = get_next_line(fd);
		ft_putstr(str);
		free(str);
		i++;
	}
	close(fd);
}
	get_next_line(fd);
	fd = open("", O_RDONLY);
//	fd = 0;
	i = 0;
	if (fd == -1)
		return (1);
	while (i < 7)
	{
		str = get_next_line(fd);
		ft_putstr(str);
		free(str);
		i++;
	}
	close(fd);
}*/
//
//
//
//
//
//
//
//
//
