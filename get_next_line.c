/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:48 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/12 19:21:31 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int 		ret;
	char 		buf[BUFFER_SIZE + 1];
	static char *tab[OPEN_MAX]; 
	char 		*tmp;

	if(fd < 0 || line == NULL)
		return (-1);
	while(ret = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[ret] = '\0';
		if(tab[fd] == NULL)
			tab[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(tab[fd], buf);
			free(tab[fd]);
			tab[fd] = tmp;
		}
		if(ft_strchr(tab[fd], '\n'))
			break;
	}
	
}

int get_line(char **tab, char **line)
{
	int len;
	char *tmp;
}