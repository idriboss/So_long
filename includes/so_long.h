/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:32:34 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/25 17:05:04 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <limits.h>

# define SPRITE_FRAME 6000

# define IMAGE_SIZE 64
# define MAP_ERROR 2
# define MALLOC_FAILED "syscall: malloc failed"
# define OPEN_FAILED "syscall: open function failed"

# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define REVERSE_PLAYER 'R'
# define EXIT 'E'
# define MONSTER 'M'
# define M_RIGHT 'I'
# define M_LEFT 'L'
# define M_UP 'U'
# define M_DOWN 'D'

# define BLACK_PATH "./images/black.xpm"
# define WALL_PATH "./images/tree.xpm"
# define FLOOR_PATH "./images/ground.xpm"
# define COLLECT_PATH "./images/wood.xpm"
# define PLAYER_PATH "./images/player_right.xpm"
# define REVERSE_PLAYER_PATH "./images/player_left.xpm"
# define EXIT_PATH "./images/house.xpm"
# define DESTROYED_EXIT_PATH "./images/destroyed_house.xpm"
# define GG_PATH "./images/gg.xpm"
# define LOSE_PATH "./images/lose.xpm"
# define M_RIGHT_PATH "./images/M_right.xpm"
# define M_LEFT_PATH "./images/M_left.xpm"
# define M_UP_PATH "./images/M_up.xpm"
# define M_DOWN_PATH "./images/M_down.xpm"
# define TREE1 "./images/trees/Tree1.xpm"
# define TREE2 "./images/trees/Tree2.xpm"
# define TREE3 "./images/trees/Tree3.xpm"
# define TREE4 "./images/trees/Tree4.xpm"
# define TREE5 "./images/trees/Tree5.xpm"
# define TREE6 "./images/trees/Tree6.xpm"

# define DISPLAY 'D'
# define IMAGE 'I'
# define WINDOW 'W'

# define WINDOW_X_SIZE 1920
# define WINDOW_Y_SIZE 1080

typedef struct t_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*final_image;
	void	*player;
	void	*reverse_player;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
	void	*destroyed_exit;
	void	*black;
	void	*m_up;
	void	*m_down;
	void	*m_right;
	void	*m_left;
	void	*lose;
	void	*gg;
	void	**trees;
	int		gg_x_size;
	int		gg_y_size;
}	t_mlx;

typedef struct t_data
{
	t_mlx		*mlx;
	char		**map;
	int			*wall_pos;
	int			wall_count_x2;
	int			collectible_count;
	int			map_y_length;
	int			map_x_length;
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;
	bool		finish;
}	t_data;

void	free_and_exit(const char *err, int code, t_data *data);
char	*map(const char *map_path, t_data *data);
void	init_map(t_data *data, char *map_path);
void	check_map(char **map, t_data *data, char **to_free, char ***to_free2d);
int		check_map_ways(char **map);
void	init_player(t_data *data);
t_data	*init_data(char **argv);
void	set_images(t_mlx *mlx, t_data *data);
int		move(int code, t_data *data);
void	put_images(t_data *data, char type, int y, int x);
void	map_images(t_data *data);
void	open_images(t_mlx *mlx, t_data *data);
int		finish(t_data *data);
void	image_to_window(t_data *data, void *type, int y, int x);
void	destroy_mlx(t_mlx *mlx);
void	ft_mlx_destroy_ptr(void **ptd, char ptr_type, t_mlx *mlx);
void	*check_image(char *file_path, t_mlx *mlx, t_data *data);
int		animation(t_data *data);
void	put_step_count(t_data *data);

#endif