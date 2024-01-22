/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:51:15 by yugao             #+#    #+#             */
/*   Updated: 2024/01/22 01:19:22 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*fin;
	size_t	i;

	i = 0;
	fin = (char *) malloc (element_size * num_elements);
	if (!fin)
		return (0);
	while (i < num_elements * element_size)
		fin[i++] = 0;
	return ((void *)fin);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen ((char *)str1);
	len2 = ft_strlen ((char *)str2);
	if (!str1 || !str2)
		return (0);
	result = (char *) malloc (sizeof (char) * (len1 + len2 + 1));
	if (!result)
		return (0);
	ft_strlcpy (result, str1, len1 + 1);
	ft_strlcat (result, (char *)str2, len1 + len2 + 1);
	return (result);
}
