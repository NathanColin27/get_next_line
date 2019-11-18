/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:17:12 by marandre          #+#    #+#             */
/*   Updated: 2019/11/18 18:04:24 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strdel(char **as, char **str, int frenum, int ret)
{
	if (!(as == NULL))
	{
		free(*as);
		*as = NULL;
	}
	if (frenum == 2)
	{
		if (!(str == NULL))
		{
			free(*str);
			*str = NULL;
		}
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*s[OPEN_MAX];
	char			*buf;
	char			*tmp;
	int				ret;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!s[fd] && !(s[fd] = ft_calloc(1, sizeof(char *))))
		return (-1);
	while ((ft_char('\n', s[fd])) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buf);
	}
	*line = ft_substr(s[fd], 0, ft_strlen(s[fd], 1));
	if ((ft_char('\n', s[fd])) < 0)
		return (ft_strdel(&s[fd], &buf, 2, 0));
	tmp = s[fd];
	s[fd] = ft_substr(s[fd], ft_char('\n', s[fd]) + 1, ft_strlen(s[fd], 0));
	return (ft_strdel(&tmp, &buf, 2, 1));
}
