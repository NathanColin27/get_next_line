/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:45 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/18 16:34:13 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del_tab(char **tab)
{
	if (tab != NULL && *tab != NULL)
		free(*tab);
		*tab = NULL;
}

size_t		ft_strlen(const char *str)
{
	size_t total;

	total = 0;
	while (*str)
	{
		total++;
		str++;
	}
	return (total);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) != 0)
	{
		if (start < ft_strlen(s))
			while (i < len && *(s + start + i))
			{
				result[i] = *(s + start + i);
				i++;
			}
		result[i] = '\0';
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(total * sizeof(char))))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char const *str, int c)
{
	char a;

	a = c;
	while (*str)
	{
		if (*str == a)
			return (char *)(str);
		str++;
	}
	if (*str == a)
		return (char *)(str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
