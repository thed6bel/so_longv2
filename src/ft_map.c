/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:35:39 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 13:27:04 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_draw(char **map, t_data *data)
{
	char	*moves;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			data->img = mlx_xpm_file_to_image(data->mlx, ft_path_xpm(map[i][j],
						data), &data->width, &data->height);
			if (!data->img)
				exit (1);
			mlx_put_image_to_window(data->mlx, data->win, data->img,
				j * 32, i * 32);
			j++;
		}
		i++;
	}
	moves = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->win, 5, 5, 0x0000FF00, moves);
	free(moves);
}

char	*ft_path_xpm(char map, t_data *data)
{
	if (map == 'P' && data->sens == 0)
		return ("image/luffyl.xpm");
	if (map == 'P')
		return ("image/luffy.xpm");
	if (map == '0')
		return ("image/woodfloor.xpm");
	if (map == '1')
		return ("image/grasswall.xpm");
	if (map == 'E' && data->collectible == 0)
		return ("image/openfridge.xpm");
	if (map == 'E' && data->collectible != 0)
		return ("image/closefridge.xpm");
	if (map == 'C')
		return ("image/chicken.xpm");
	return (NULL);
}
