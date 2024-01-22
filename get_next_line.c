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

char	*get_next_line(int fd)
{
	static char	*buffer = {NULL};
	int			len_read;


	len_read = 0;
	if (fd < 0)
		return (NULL);
	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof (char));
	if (!buffer)
		return (NULL);
	len_read = read (fd, buffer, BUFFER_SIZE);
	if (len_read <= 0)
		return (NULL);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*content;

	fd = open ("/Users/mac/Desktop/get_next_line/test.txt", O_RDONLY);
	content = get_next_line (fd);
	while (content)
	{
		printf ("We extract sucessfully a string from the document givened :%s\n", content);
		content = get_next_line (fd);
	}
	close (fd);
	return (0);
}
