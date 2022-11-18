/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:48:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/18 15:04:51 by hqureshi         ###   ########.fr       */
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
#define mapWidth 24
#define mapHeight 24

enum color {
    RGB_RED = 0xFF0000FF,
    RGB_GREEN = 0x00FF00FF,
    RGB_BLUE = 0x0000FFFF,
    RGB_WHITE = 0xFFFFFFFF,
};

typedef struct s_data {
    mlx_t       *mlx;
    // mlx_texture *mlx_texture;
    mlx_image_t *mlx_image;
    int         mapX;
    int         mapY;
    double      posX;
    double      posY;
}       t_data;

// main.c
int		main(void);

// cub3d.c
void	cub3d(void);

// manageInput.c
void draw_wall(t_data *data);
void draw_floor_ceiling(t_data *data);

#endif