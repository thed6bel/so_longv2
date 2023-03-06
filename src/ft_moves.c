/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:17:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 13:31:12 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_win(t_data *data)
{
	ft_printf("Luffy can finally eat everything in the fridge, THANKS\n");
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit (0);
}

int	ft_up_move(t_data *data)
{
	if (data->map[data->y - 1][data->x] == '1')
		return (0);
	else if (data->map[data->y - 1][data->x] == 'C')
	{
		data->map[data->y - 1][data->x] = '0';
		ft_swap(&data->map[data->y][data->x], &data->map[data->y - 1][data->x]);
		data->collectible--;
		data->y--;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	else if (data->map[data->y - 1][data->x] == 'E' && data->collectible == 0)
		ft_win(data);
	else if (data->map[data->y - 1][data->x] == '0')
	{
		ft_swap(&data->map[data->y][data->x], &data->map[data->y - 1][data->x]);
		data->y--;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	return (0);
}

int	ft_right_move(t_data *data)
{
	data->sens = 1;
	if (data->map[data->y][data->x + 1] == '1')
		return (0);
	else if (data->map[data->y][data->x + 1] == 'C')
	{
		data->map[data->y][data->x + 1] = '0';
		ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x + 1]);
		data->collectible--;
		data->x++;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	else if (data->map[data->y][data->x + 1] == 'E' && data->collectible == 0)
		ft_win(data);
	else if (data->map[data->y][data->x + 1] == '0')
	{
		ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x + 1]);
		data->x++;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	return (0);
}

int	ft_left_move(t_data *data)
{
	data->sens = 0;
	if (data->map[data->y][data->x - 1] == '1')
		return (0);
	else if (data->map[data->y][data->x - 1] == 'C')
	{
		data->map[data->y][data->x - 1] = '0';
		ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x - 1]);
		data->collectible--;
		data->x--;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	else if (data->map[data->y][data->x - 1] == 'E' && data->collectible == 0)
		ft_win(data);
	else if (data->map[data->y][data->x - 1] == '0')
	{
		ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x - 1]);
		data->x--;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	return (0);
}

int	ft_down_move(t_data *data)
{
	if (data->map[data->y + 1][data->x] == '1')
		return (0);
	else if (data->map[data->y + 1][data->x] == 'C')
	{
		data->map[data->y + 1][data->x] = '0';
		ft_swap(&data->map[data->y][data->x], &data->map[data->y + 1][data->x]);
		data->collectible--;
		data->y++;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	else if (data->map[data->y + 1][data->x] == 'E' && data->collectible == 0)
		ft_win(data);
	else if (data->map[data->y + 1][data->x] == '0')
	{
		ft_swap(&data->map[data->y][data->x], &data->map[data->y + 1][data->x]);
		data->y++;
		data->moves++;
		ft_printf("moves : %d\n", data->moves);
	}
	return (0);
}
