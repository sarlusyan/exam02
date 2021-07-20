/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusargsy <lusargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:29:33 by naapikya          #+#    #+#             */
/*   Updated: 2021/05/24 13:10:39 by lusargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	int		i;
	int		r;
	char	buffer;
	char	*str;

	if (!(str = (char *)malloc(10000)) || !line)
		return (-1);
	i = 0;
	while ((r = read(fd, &buffer, 1)) && buffer != '\n' && buffer != '\0')
	{
		if (buffer != '\n' && buffer != '\0')
			str[i] = buffer;
		i++;
	}
	str[i] = '\0';
	*line = str;
	return (r);
}

int 	main()
{
	int fd;
	char *line;

	fd = open("./test.txt", O_RDONLY);
	get_next_line(fd, &line);
}
