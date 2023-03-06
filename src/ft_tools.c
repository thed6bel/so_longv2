/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:18:24 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 15:07:18 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit (0);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	ft_printf("You have chosen to leave so_long\n");
	exit (0);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
