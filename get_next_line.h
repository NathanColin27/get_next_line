/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:42:40 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/18 16:22:55 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
//#define BUFFER_SIZE 10

#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);
void	del_tab(char **tab);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(const char *s1);

#endif