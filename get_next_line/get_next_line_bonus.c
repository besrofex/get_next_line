/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:22:17 by ylabser           #+#    #+#             */
/*   Updated: 2024/12/15 15:24:44 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_update(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!str)
		return (NULL);
	i = ft_strlen_bonus(str);
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (i == j)
		return (free(str), str = NULL, NULL);
	j++;
	tmp = ft_strdup_bonus(str + j);
	return (free(str), str = NULL, tmp);
}

static char	*get_line(char *str)
{
	int		i;
	char	*line;

	if (!(*str) || !str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[++i] = '\0';
	return (line);
}

static char	*creat_array(char *str, int fd)
{
	size_t		read_count;
	char		*tmp;

	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	read_count = read(fd, tmp, BUFFER_SIZE);
	if (!str)
		str = ft_init_bonus(NULL);
	while (read_count > 0)
	{
		str = ft_strjoin_bonus(str, tmp, read_count);
		if (found_newline_bonus(tmp))
			break ;
		read_count = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*reserve[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 10240
		|| BUFFER_SIZE > INT_MAX)
	{
		if (fd >= 0 && fd <= 10240) 
			return (free(reserve[fd]), reserve[fd] = NULL, NULL);
		return (NULL);
	}
	reserve[fd] = creat_array(reserve[fd], fd);
	if (reserve[fd] == NULL)
		return (free(reserve[fd]), reserve[fd] = NULL, NULL);
	line = get_line(reserve[fd]);
	if (!line)
		return (free(reserve[fd]), reserve[fd] = NULL, NULL);
	reserve[fd] = ft_update(reserve[fd]);
	return (line);
}
