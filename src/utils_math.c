/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/10 20:20:54 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (!str || str[i] != '\0')
		i++;
	return (i);
}

int	ft_len_digits(unsigned int n)
{
	if (n < 10)
		return (1);
	return (ft_len_digits(n / 10) + 1);
}

int	ft_is_negative(int n)
{
	return (n < 0);
}

int	ft_putchar_fd(int c, int fd)
{
	write(1, &c, fd);
	return (fd);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}
