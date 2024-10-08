/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:09:15 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 15:01:54 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_valide_ext(char *map)
{
	int	end;

	end = (ft_strlen(&map[0]) - 1);
	if (map[end] != 'r' || map[end - 1] != 'e'
		|| map[end - 2] != 'b' || map[end - 3] != '.')
		ft_error("Error\nExtension map error, only .ber maps");
}

char	**ft_map_read(char argv[1], int i)
{
	char	*str;
	char	**map;
	int		fd;

	i = 0;
	ft_valide_ext(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap cannot be read or does not exist");
	str = ft_read_line(fd);
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] == '\n' && str[i + 1] == '\0'))
			ft_error("Error\nMap error");
		i++;
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

void	ft_map_other_items(char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map [i][j] != 'C' && map [i][j] != 'P' && map [i][j] != 'E'
				&& map [i][j] != '1' && map [i][j] != '0')
				ft_error("Error\nNot recognised symbol on your map");
		}
	}
}

void	ft_map_items(char **map, int i, t_data *data)
{
	int	j;

	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map [i][j] == 'C')
				data->collectible++;
			if (map [i][j] == 'E')
				data->exit++;
			else if (map [i][j] == 'P')
			{
				data->x = j;
				data->y = i;
				data->player++;
			}
		}
	}
	if (data->exit != 1 || data->player != 1 || data->collectible < 1)
		ft_error("Error\nYou need 1 Player, 1 Exit and less 1 Collectible");
}

void	ft_edge_ctrl(char **map, size_t len, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			ft_error("Error\nMap not closed column");
	}
	data->height = i;
	if (i > 43)
		ft_error("Error\nMap too high");
	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			ft_error("Error\nMap not closed line up");
	data->width = j;
	j = -1;
	while (map[i - 1][++j])
		if (map[i - 1][j] != '1')
			ft_error("Error\nMap not closed line down");
}
