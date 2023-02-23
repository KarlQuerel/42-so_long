/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:12:37 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 20:54:53 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_write_one_line(char *stash)
{
	char	*line_to_return;
	int		i;

	if (stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line_to_return = (char *)malloc(sizeof(char) * i + 1);
	if (line_to_return == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line_to_return[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line_to_return[i++] = '\n';
	line_to_return[i] = '\0';
	return (line_to_return);
}

char	*ft_reinit_stash(char *stash)
{
	char	*new_stash;
	int		i;

	if (stash[0] == '\0')
	{
		free (stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = ft_substr_gnl(stash, (i), ft_strlen_gnl(stash) - i);
	free (stash);
	stash = NULL;
	return (new_stash);
}

char	*ft_sub_or_join(char *stash, char *buffer)
{
	char	*new_stash;

	if (stash == NULL)
		new_stash = ft_substr_gnl(buffer, 0, BUFFER_SIZE);
	else
		new_stash = ft_strjoin(stash, buffer);
	free (stash);
	stash = NULL;
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer_or_return;
	int			ret_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_or_return = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer_or_return == NULL)
		return (NULL);
	ret_read = 42;
	while (ft_strchr_gnl(stash[fd], '\n') == 0 && ret_read != 0)
	{
		ret_read = read(fd, buffer_or_return, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free (buffer_or_return);
			return (NULL);
		}
		buffer_or_return[ret_read] = '\0';
		stash[fd] = ft_sub_or_join(stash[fd], buffer_or_return);
	}
	free (buffer_or_return);
	buffer_or_return = ft_write_one_line(stash[fd]);
	stash[fd] = ft_reinit_stash(stash[fd]);
	return (buffer_or_return);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd;
	fd = open("test", O_RDONLY);
	printf("fd = :%i:\n", fd);
	i = 1;
	line = get_next_line(fd);
	printf("line [%d]: %s", i, line);
	free(line);
	i++;
	while (line)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
