/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:52:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/03/06 10:29:17 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
#include <unistd.h>


typedef struct s_data
{
	int			exit;
	int			collectible;
	int			player;
	int			width;
	int			height;
	int			x;
	int			y;
	int			sens;
	int			moves;
	size_t		len;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
}				t_data;

int		ft_key_input(int key, t_data *param);
int		*ft_free_map(char **map);
void	ft_error(char *message);
int		ft_close(t_data *data);
void	ft_swap(char *a, char *b);
int		ft_up_move(t_data *data);
int		ft_right_move(t_data *data);
int		ft_left_move(t_data *data);
int		ft_down_move(t_data *data);
void	ft_mlx(char **map, t_data *data);
void	ft_map_draw(char **map, t_data *data);
char	*ft_path_xpm(char map, t_data *data);
char	**ft_map_read(char argv[1], int i);
size_t	ft_map_len(char **map);
void	ft_map_items(char **map, int i, t_data *data);
void	ft_map_not_items(char **map, int i, t_data *data);
void	ft_map_ctrl(char **map, size_t len, t_data *data);
void	ft_map_valid(char **map, t_data *data);
char	*ft_read_line(int fd);


#endif