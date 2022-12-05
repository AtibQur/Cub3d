/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:36:22 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/05 14:31:24 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(0.1) - player->dir_y * sin(0.1);
	player->dir_y = old_dir_x * sin(0.1) + player->dir_y * cos(0.1);
	player->plane_x = player->plane_x * cos(0.1) - player->plane_y * sin(0.1);
	player->plane_y = old_plane_x * sin(0.1) + player->plane_y * cos(0.1);
}

void	rotate_right(t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-0.1) - player->dir_y * sin(-0.1);
	player->dir_y = old_dir_x * sin(-0.1) + player->dir_y * cos(-0.1);
	player->plane_x = player->plane_x * cos(-0.1) - player->plane_y * sin(-0.1);
	player->plane_y = old_plane_x * sin(-0.1) + player->plane_y * cos(-0.1);
}