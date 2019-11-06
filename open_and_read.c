/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:08:04 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/22 16:25:30 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


#define BUFF_SIZE 50

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

int strlen_line(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
		if(str[i] =='\n')
			return (i);
	}
	return (0);
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
		return (0);
	while (*s1 && *s1 != '\n')
		str[i++] = *s1++;
	while (*s2 && *s2 != '\n')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}


void    ft_putstr(char *tab)
{
    int i;

    i = 0;
    while(tab[i])
    {
        write(1, &tab[i], 1);
        i++;
    }
}

int				new_line(char *str)
{
	while(*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	int 		ret;
	char		*ligne;

	
	ligne = "";
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	while(!(strlen_line(ligne)))
	{
		ligne = ft_strjoin(ligne, buf);
		printf("%d",strlen_line(ligne));
		ret = read(fd, buf, BUFF_SIZE);
		if(ret == 0)
			break;
		// printf("%s\n", ligne);
		buf[ret] = '\0';
	}
	
	*line = ligne;
	return 0;
}


int				main(int argc, char **argv)
{
	int			fd;
	char		*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("ma ligne = %s\n", line);
		get_next_line(fd, &line);
		printf("ma ligne = %s\n", line);
	}
	return (0);
}