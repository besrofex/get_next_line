/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:22:36 by ylabser           #+#    #+#             */
/*   Updated: 2024/12/12 18:01:01 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	found_newline_bonus(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_bonus(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	int		len;
	char	*buffer;

	len = ft_strlen_bonus(s1) + size;
	buffer = malloc(len + 1);
	if (!buffer || !s2)
		return (NULL);
	if (!s1)
		s1 = ft_init_bonus(NULL);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	j = 0;
	while (s2[j] != '\0' && j < size)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_strdup_bonus(char *s)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen_bonus(s);
	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_init_bonus(char *str)
{
	char	*buffer;

	if (!str)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
		return (buffer);
	}
	return (str);
}
