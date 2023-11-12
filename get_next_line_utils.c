/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:22:29 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/04 16:56:20 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i ++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[j] = s[start + i];
			j ++;
		i ++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sub = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s2 || !sub)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			sub[i] = s1[i];
			i ++;
		}
	}
	while (s2[j] != '\0')
	{
		sub[i + j] = s2[j];
		j ++;
	}
	sub[i + j] = '\0';
	return (sub);
}

/**
 * The function `ft_joinandfree` concatenates two strings and frees the memory of the first string.
 * 
 * @param s1 A pointer to the first string to be joined and freed.
 * @param s2 A pointer to a string that you want to join with s1.
 * 
 * @return a pointer to a character, which is the result of concatenating `s1` and `s2` using the
 * `ft_strjoin` function.
 */
char	*ft_joinandfree(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}
