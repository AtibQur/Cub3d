/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:05:59 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/14 10:26:27 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * player->move_speed)] == '0')
		player->pos_x += player->dir_x * player->move_speed;
	if (map[(int)(player->pos_y + player->dir_y * player->move_speed)]
			[(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_y * player->move_speed;
}

void	move_backward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x - player->dir_x * player->move_speed)] == '0')
		player->pos_x -= player->dir_x * player->move_speed;
	if (map[(int)(player->pos_y - player->dir_y * player->move_speed)]
			[(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_y * player->move_speed;
}

void	move_left(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x - player->plane_x * player->move_speed)]
			== '0')
		player->pos_x -= player->plane_x * player->move_speed;
	if (map[(int)(player->pos_y - player->plane_y * player->move_speed)]
			[(int)(player->pos_x)] == '0')
		player->pos_y -= player->plane_y * player->move_speed;
}

void	move_right(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->plane_x * player->move_speed)]
			== '0')
		player->pos_x += player->plane_x * player->move_speed;
	if (map[(int)(player->pos_y + player->plane_y * player->move_speed)]
			[(int)(player->pos_x)] == '0')
		player->pos_y += player->plane_y * player->move_speed;
}
