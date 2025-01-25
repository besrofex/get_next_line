/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:22:29 by ylabser           #+#    #+#             */
/*   Updated: 2024/12/08 14:14:55 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strjoin_bonus(char *s1, char *s2, int size);
size_t		ft_strlen_bonus(char *str);
char		*ft_strdup_bonus(char *s);
int			found_newline_bonus(char	*str);
char		*ft_init_bonus(char *str);

#endif