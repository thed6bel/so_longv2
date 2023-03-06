/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:25:16 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:12:58 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_free_read_line(char *buff)
{
	free(buff);
	ft_error("Error\nProblem with your map");
	return (NULL);
}

char	*ft_read_line(int fd)
{
	char	*buff;
	char	*str;
	size_t	i;

	str = NULL;
	buff = malloc(2);
	if (!buff)
		return (NULL);
	i = 1984;
	while (i > 0)
	{
		i = read(fd, buff, 1);
		if (i < 0)
			return (ft_free_read_line(buff));
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (ft_free_read_line(buff));
		if (str[0] == '\0')
			return (ft_free_read_line(buff));
	}
	free(buff);
	return (str);
}
