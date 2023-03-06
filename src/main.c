/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:34:32 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:58:59 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key_input(int key, t_data *program)
{
	if (key == 124 || key == 2)
		ft_right_move(program);
	else if (key == 123 || key == 0)
		ft_left_move(program);
	else if (key == 125 || key == 1)
		ft_down_move(program);
	else if (key == 126 || key == 13)
		ft_up_move(program);
	else if (key == 53)
		ft_close(program);
	mlx_clear_window(program->mlx, program->win);
	ft_map_draw(program->map, program);
	return (0);
}

size_t	ft_map_len(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error("Error\nMap need to be a rectangle\n");
		i++;
	}
	if (len >= 60)
		ft_error("Error\nMap too large\n");
	return (len);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**map;
	size_t		len;
	int			i;

	if (argc != 2)
		ft_error("Error\nChose a valide map please!");
	else
	{
		data = malloc(sizeof(t_data));
		i = 0;
		map = ft_map_read(argv[1], i);
		if (!map)
			ft_error("Error\nProblem with your map");
		len = ft_map_len(map) - 1;
		i = -1;
		ft_map_items(map, i, data);
		ft_map_other_items(map, i);
		ft_edge_ctrl(map, len, data);
		ft_path_valid(map, data);
		ft_free_map(map);
		map = ft_map_read(argv[1], i);
		ft_mlx(map, data);
	}
	return (1);
}
