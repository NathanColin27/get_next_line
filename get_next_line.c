/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:48 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/15 12:14:51 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int add_line(char **tab, char **line)
{
	int len;
	char *tmp;
	len = 0;

	while ((*tab)[len] != '\0' && (*tab)[len] != '\n')
		len++;
	if ((*tab)[len] == '\n')
	{
		*line = ft_substr(*tab, 0, len);
		tmp = ft_strdup(&((*tab)[len + 1]));
		free(*tab);
		*tab = tmp;
		if ((*tab)[0] == '\0')
			del_tab(tab);
	}
	else 
	{
		*line = ft_strdup(*tab);
		del_tab(tab);
	}
	return (1);
}

int get_next_line(int fd, char **line)
{
	int 		ret;
	char 		buf[BUFFER_SIZE + 1];
	static char *tab[OPEN_MAX]; 
	char 		*tmp;
	*line  = "";
	if(fd < 0 || line == NULL)
		return (-1);
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("ret = %d\n", ret);
		buf[ret] = '\0';
		if(tab[fd] == NULL)
		{
			tab[fd] = ft_strdup(buf);
		}
		else
		{
			tmp = ft_strjoin(tab[fd], buf);
			free(tab[fd]);
			tab[fd] = tmp;
		}
		if(ft_strchr(tab[fd], '\n'))
			break;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && tab[fd] == NULL)
		return (0);
	else
		add_line(&tab[fd], line);
	return (1);
}



int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  return (0);
 }