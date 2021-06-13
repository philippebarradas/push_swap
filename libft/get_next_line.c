/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:03:31 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/13 13:29:44 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	if (str[0] == '\n')
	{
		rtn[0] = '\n';
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

void	fffree(char *save, char **line)
{
	save = get_save(save);
	if (ft_strcmp(*line, "sa") != 0 && ft_strcmp(*line, "sb") != 0
		&& ft_strcmp(*line, "ss") != 0 && ft_strcmp(*line, "pa") != 0
		&& ft_strcmp(*line, "pb") != 0 && ft_strcmp(*line, "ra") != 0
		&& ft_strcmp(*line, "rb") != 0 && ft_strcmp(*line, "rr") != 0
		&& ft_strcmp(*line, "rra") != 0 && ft_strcmp(*line, "rrb") != 0
		&& ft_strcmp(*line, "rrr") != 0)
		free(save);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!has_return(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	fffree(save, line);
	if (reader == 0)
		return (0);
	return (1);
}
