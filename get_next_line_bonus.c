/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:00:39 by adube             #+#    #+#             */
/*   Updated: 2023/05/31 12:30:41 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_call_prep(char *s)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(s) - i + 1), sizeof(char));
	i++;
	while (s[i])
		new_line[j++] = s[i++];
	free(s);
	return (new_line);
}

char	*define_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && str[i])
		line[i++] = '\n';
	return (line);
}

char	*join_free(char *result, char *buffer)
{
	char	*joined;

	joined = str_join(result, buffer);
	free(result);
	return (joined);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		count_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	count_read = 1;
	while (count_read > 0)
	{
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count_read] = 0;
		result = join_free(result, buffer);
		if (string_search(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = define_line(buffer);
	buffer = next_call_prep(buffer);
	return (line);
}
