/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 09:48:29 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/02 14:23:42 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <memory.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 5
#define mapHeight 5

// int worldMap[mapWidth][mapHeight] = 
// {
//   {1,1,1,1,1},
//   {2,0,0,0,4},
//   {2,0,0,0,4},
//   {2,0,0,0,4},
//   {3,3,3,3,3}
// };

enum color {
    RGB_RED = 0xFF0000FF,
    RGB_GREEN = 0x00FF00FF,
    RGB_BLUE = 0x0000FFFF,
    RGB_WHITE = 0xFFFFFFFF,
};

typedef struct	s_player {
    double      pos_x;
    double      pos_y;
	double      dir_x;
    double      dir_y;
	double      plane_x;
    double      plane_y;
    double      camera_x;
}				t_player;

typedef struct	s_ray {
	int			column_x;
	int			map_x;
	int			map_y;
	int			hit;
 	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
    int         step_x;
    int         step_y;
    int         side;
    double      camera_x;
	double		raydir_x;
 	double		raydir_y;
	double 		deltadist_x;
	double 		deltadist_y;
	double		sidedist_x;
    double		sidedist_y;
	double 		walldist;
}				t_ray;

typedef struct	s_data {
    mlx_t           *mlx;
    mlx_image_t 	*mlx_image;
	t_player 		*player;
	// t_ray 	        *ray;
    // int         f_color;
    // int         c_color;
    // int         n_text;
    // int         e_text;
    // int         s_text;
    // int         w_text;
    int         player_dir;
}				t_data;

// main.c
int		main(void);

// cub3d.c
void	cub3d(void);

// manageInput.c
void    draw_wall(t_data *data);
void    draw_floor_ceiling(t_data *data);
void    draw_vertical_line(t_data *data, t_ray *ray);

// hook.c
void		hook(void *param);

//init all data
void    	init_data(t_data *data);
t_player 	init_player(t_data *data);
void	    init_ray_to_zero(t_ray *ray);
void	    init_ray(t_data *data, t_ray *ray);

//raycast
void intersect(double pos_x, double pos_y, t_ray *ray);
void dda(t_ray *ray);
void    calculate_wall_height(t_ray *ray);
void    get_color(t_ray *ray);

//parse
#endif