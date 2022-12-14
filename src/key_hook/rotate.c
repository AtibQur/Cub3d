/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:36:22 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/14 10:28:03 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_player *player, double move_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(move_speed)
		- player->dir_y * sin(move_speed);
	player->dir_y = old_dir_x * sin(move_speed)
		+ player->dir_y * cos(move_speed);
	player->plane_x = player->plane_x * cos(move_speed)
		- player->plane_y * sin(move_speed);
	player->plane_y = old_plane_x * sin(move_speed)
		+ player->plane_y * cos(move_speed);
}
