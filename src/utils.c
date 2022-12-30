/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/28 18:59:38 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_buff(int fd)
{
	char	*buff;
	char	*slice;
	int		*bytes_transfer;
	int		bytes_read;

	if (BUFFER_SIZE < 0)
		return (NULL);
	bytes_transfer = malloc(BUFFER_SIZE * sizeof(int *));
	*bytes_transfer = BUFFER_SIZE;
	buff = malloc(BUFFER_SIZE * sizeof(char *) + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, *bytes_transfer);
	free(bytes_transfer);
	if (bytes_read < 1)
	{
		free(buff);
		return (NULL);
	}
	buff[bytes_read] = '\0';
	slice = ft_strdup(buff);
	free(buff);
	return (slice);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (*str)
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_char_append(char *s1, char c)
{
	int		i;
	char	*m;

	if (!s1 || !c)
		return (NULL);
	m = malloc((ft_strlen(s1) + sizeof(c)) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = c;
	i++;
	m[i] = '\0';
	free(s1);
	return (m);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				negative;
	unsigned int	nb;

	nb = n;
	negative = ft_is_negative(n);
	if (negative)
		nb = n * (-1);
	len = ft_len_digits(nb) + negative;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
