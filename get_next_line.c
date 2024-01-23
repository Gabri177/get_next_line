/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:51:17 by yugao             #+#    #+#             */
/*   Updated: 2024/01/22 01:22:01 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_free(char *dir)
{
	if (dir)
	{
		free (dir);
		dir = NULL;
		return (NULL);
	}
	return (NULL);
}

static char	*re_read(int fd, char *buf)
{
	char	*tem;
	char	*new;
	int		byt_read;

	tem = ft_calloc (BUFFER_SIZE + 1, sizeof (char));
	if (!tem)
		return (NULL);
	byt_read = read (fd, tem, BUFFER_SIZE);
	if (*tem == '\0')
		return (NULL);
	if (byt_read <= 0)
	{
		ft_free (tem);
		if (byt_read == 0 && buf)
			return (buf);
		return (NULL);
	}
	if (!buf)
		return (tem);
	new = ft_strjoin (buf, tem);
	ft_free (buf);
	ft_free (tem);
	//printf ("buf : ==%s==\n", new);
	return (new);
}

static char	*ft_cutbuf(char *str)
{
	char	*tem;
	char	*tem2;

	tem2 = str;
	while (*str)
	{
		if (*str == '\n')
		{
			tem = malloc (sizeof (char) * (ft_strlen (str + 1) + 1));
			if (!tem)
				return (NULL);
			ft_strlcpy (tem, str + 1, ft_strlen (str + 1) + 1);
			ft_free (tem2);
			return (tem);
		}
		str ++;
	}
	return (str);
}

static char *ft_line (char *str) // 修改
{
	size_t	end;
	char	*tem;
	char	*cp;

	end = 0;
	cp = str;
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
		{
			tem = malloc (sizeof (char) * (end + 2));
			if (!tem)
				return (NULL);
			ft_strlcpy (tem, cp, end + 2);
			return (tem);
		}
		str ++;
		end ++;
	}
	return (NULL);
	
}

char	*get_next_line(int fd)
{
	static char	*buffer = {NULL};
	char		*tem;

	if (fd < 0)
		return (NULL);
	while (1)
	{
		buffer = re_read (fd, buffer);
		if (!buffer)
			return (NULL);
		tem = ft_line (buffer);
		//printf ("while(1): ==%s==\n", tem);
		if (tem)
		{
			//printf ("while(1): ==%s==\n", tem);
			buffer = ft_cutbuf (buffer);
			break ;
		}
		//printf ("while(1): ==%s==\n", buffer);
	}
	//printf ("fin : %s\n", tem);
	return (tem);
}

int	main(void)
{
	int		fd;
	char	*content;

	fd = open ("./test.txt", O_RDONLY);
	//printf ("fd:open ==%d==\n", fd);
	content = get_next_line (fd);
	printf ("1. We extract:%s\n", content);
	content = get_next_line (fd);
	printf ("2. We extract:%s\n", content);
	content = get_next_line (fd);
	printf ("3. We extract:%s\n", content);
	content = get_next_line (fd);
	printf ("4. We extract:%s\n", content);
	content = get_next_line (fd);
	//content = get_next_line (fd);
	printf ("5. We extract:%s\n", content);
	content = get_next_line (fd);
	printf ("6. We extract:%s\n", content);
	close (fd);
	return (0);
}