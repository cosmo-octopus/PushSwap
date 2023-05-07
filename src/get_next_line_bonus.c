/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:21:30 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:21:33 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_get_remainder(char *buffer)
{
	char	*rmndr;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rmndr = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!rmndr)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		rmndr[j++] = buffer[i++];
	rmndr[j] = '\0';
	free(buffer);
	return (rmndr);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_read_and_save(int fd, char *buffer)
{
	int		byte_read;
	char	buff[BUFFER_SIZE + 1];

	byte_read = 1;
	*buff = 0;
	while (!ft_strchr(buff, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
		{
			if (buffer)
				free (buffer);
			return (NULL);
		}
		buff[byte_read] = '\0';
		if (!buffer)
			buffer = ft_strdup(buff);
		else
			buffer = ft_strjoin(buffer, buff);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		if (buffer[fd])
			free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = ft_read_and_save(fd, buffer[fd]);
	if (!buffer[fd])
	{
		return (NULL);
	}
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_get_remainder(buffer[fd]);
	return (line);
}
