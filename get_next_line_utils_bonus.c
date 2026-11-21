/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:35:43 by akella            #+#    #+#             */
/*   Updated: 2024/12/15 16:41:16 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	if (!s1 && s2)
	{
		l2 = ft_strlen(s2);
		s3 = ft_calloc(l2 + 1, sizeof(char));
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s2, l2 + 1);
		return (s3);
	}
	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, l1 + 1);
	ft_strlcpy(s3 + l1, s2, l2 + 1);
	free(s1);
	return (s3);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		ptr[i++] = 0;
	return ((void *)ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		len;

	s = src;
	len = ft_strlen(s);
	if (dstsize == 0)
		return (len);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
