/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:26:00 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/06 12:05:45 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define BUFF_SIZE 10

int		new_line(char *str)
{
	while(*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int		ft_strlen(const char *str)
{
	int total;

	total = 0;
	while (*str)
	{
		total++;
		str++;
	}
	return (total);
}

static	char	*ft_strcut(char (*str)[BUFF_SIZE + 1], int n)
{
	int i;

	if (n == 0)
		return (*str);
	i = 0;
	while ((*str)[n + i])
	{
		(*str)[i] = (*str)[i + n];
		i++;
	}
	(*str)[i] = '\0';
	return (*str);
}

static	int		strlenb(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_until_new_line(char const *s1, char const *s2)
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
	while (*s1 && *s1 != '\n')
		str[i++] = *s1++;
	while (*s2 && *s2 != '\n')
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


int get_next_line(int fd, char **line)
{
	int				ret;
	static char 	buf[BUFF_SIZE + 1];
	char			*ligne;

	ligne = "";
	ft_strcut(&buf, strlenb(buf) + 1);
	ligne = ft_strjoin_until_new_line(ligne, buf);
	
	while(ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ligne = ft_strjoin_until_new_line(ligne, buf);
		*line = ligne;
		usleep(10000);
		if(new_line(buf))
		{	
			break;
		}
		
	}
	*line = ligne;
	return(0);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i  = 0;
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n",line);
		get_next_line(fd, &line);
		printf("%s\n",line);
		get_next_line(fd, &line);
		printf("%s\n",line);
		get_next_line(fd, &line);
		printf("%s\n",line);
		get_next_line(fd, &line);
		printf("%s\n",line);
		close(fd);
	}
}