/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:39:28 by yugao             #+#    #+#             */
/*   Updated: 2024/01/27 22:03:55 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_COUNT
#  define FD_COUNT 1300
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>

char	*find_char(char *str, char obj);
char	*ft_call(size_t size);
size_t	str_len(char *str);
char	*merge(char *str1, char *str2);
char	*str_cp(char *str, size_t len);
char	*get_next_line(int fd);
char	*ft_free(char	**str);

#endif