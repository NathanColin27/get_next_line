/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:48 by ncolin            #+#    #+#             */
/*   Updated: 2019/11/12 18:28:06 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define BUFFER_SIZE 3

int get_next_line(int fd, char **line)
{
	int ret;
	char buff[BUFFER_SIZE + 1]

	if(fd < 0 || line == NULL)
		return (-1);
	while()
}