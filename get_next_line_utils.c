/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:45 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/12 10:36:40 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	int			l;

	i = start;
	l = len;
	if (!s || ft_strlen(s) < i)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0 && *s)
	{
		*str = s[i];
		i++;
		str++;
	}
	*str = '\0';
	return (str - l);
}