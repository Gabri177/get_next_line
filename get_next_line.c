/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:38:58 by yugao             #+#    #+#             */
/*   Updated: 2024/01/26 23:39:46 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char	**str)
{
	if (!*str)
		return (NULL);
	free (*str);
	*str = NULL;
	return (NULL);
}

static char	*read_file(int fd, char *old_buf)
{
	char	*tem_buf;
	int		stat_fd;

	stat_fd = 1;
	tem_buf = ft_call (BUFFER_SIZE + 1);
	if (!tem_buf)
		return (ft_free (&old_buf));
	while (!find_char (old_buf, '\n') && stat_fd)
	{
		stat_fd = read (fd, tem_buf, BUFFER_SIZE);
		if (stat_fd < 0)
			return (ft_free (&tem_buf), ft_free (&old_buf));
		if (stat_fd > 0)
		{
			old_buf = merge (old_buf, tem_buf);
			if (!old_buf)
				return (ft_free (&tem_buf), ft_free (&old_buf));
		}
	}
	ft_free (&tem_buf);
	return (old_buf);
}

static char	*get_line(char *str)
{
	char	*tem;
	size_t	len;

	len = 0;
	if (!str)
		return (NULL);
	if (!find_char (str, '\n'))
	{
		tem = str_cp (str, str_len(str));
		if (!tem)
			return (NULL);
		return (tem);
	}
	while (str[len] != '\n' && str[len])
		len ++;
	tem = str_cp (str, len + 1);
	if (!tem)
		return (NULL);
	return (tem);
}

static char	*refresh_buf(char	*buf)
{
	char	*old;
	char	*new;

	old = buf;
	if (!buf)
		return (NULL);
	if (!find_char (buf, '\n'))
		return (NULL);
	while (*buf && *buf != '\n')
		buf ++;
	if (*buf == '\n')
	{
		buf ++;
		new = str_cp (buf, str_len (buf));
		if (!new)
			return (ft_free(&buf));
		free (old);
		return (new);
	}
	free (old);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_file (fd, buff);
	//printf ("newbuffer : |%s|\n", buff);
	if (!buff)
		return (NULL);
	line = get_line (buff);
	if (!line)
		return (NULL);
	buff = refresh_buf (buff);
	//printf ("cutbuffer : |%s|\n", buff);
	return (line);
}


/*
int main(void)
{
	int	*test;
	int	i = 0;
	int	fd;
	char	*fin;

	//test = (int *)ft_call(10);
	//printf ("**%s**", merge ("this", ""));
	//printf ("== %zu ==", str_len (merge ("", "")));
	fd = open ("./test.txt", O_RDONLY);
	//printf ("output: %s  \n", read_file(fd, fin));
	//printf ("test : --%s--\n", get_line(read_file(fd, fin)));
	//printf ("test : --%s--\n", get_line(read_file(fd, fin)));
	printf ("                      1: %s \n", get_next_line(fd));
	printf ("                      2: %s \n", get_next_line(fd));
	printf ("                      3: %s \n", get_next_line(fd));
	printf ("                      4: %s \n", get_next_line(fd));
	
	close (fd);
	return 0;
}
*/