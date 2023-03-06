/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:34:36 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:12:17 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_floodfill(char **map, int x, int y, t_data *data)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		data->exit++;
		map[y][x] = '1';
		return ;
	}
	if (map[y][x] == 'C')
		data->collectible++;
	map[y][x] = '1';
	ft_floodfill(map, x - 1, y, data);
	ft_floodfill(map, x + 1, y, data);
	ft_floodfill(map, x, y - 1, data);
	ft_floodfill(map, x, y + 1, data);
}

void	ft_path_valid(char **map, t_data *data)
{
	t_data	*backupdata;

	backupdata = malloc(sizeof(t_data));
	backupdata->collectible = 0;
	backupdata->exit = 0;
	ft_floodfill(map, data->x, data->y, backupdata);
	if (backupdata->collectible != data->collectible || backupdata->exit != 1)
	{
		free(backupdata);
		ft_error("Error\nMap error, no path finded");
	}
	free(backupdata);
}
