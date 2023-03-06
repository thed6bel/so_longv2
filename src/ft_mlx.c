/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:36:37 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 09:24:45 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mlx(char **map, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * 32,
			data->height * 32, "so_long by hucorrei");
	data->moves = 0;
	ft_map_draw(map, data);
	data->map = map;
	mlx_hook(data->win, 02, 0, &ft_key_input, data);
	mlx_hook(data->win, 17, 0, &ft_close, data);
	mlx_loop(data->mlx);
	free(map);
}
