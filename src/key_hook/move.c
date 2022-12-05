/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:05:59 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/05 15:51:34 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x + player->dir_x * 0.10)] == '0')
		player->pos_x += player->dir_x * 0.10;
	if (map[(int)(player->pos_y + player->dir_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_y * 0.10;
}

void	move_backward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x - player->dir_x * 0.10)] == '0')
		player->pos_x -= player->dir_x * 0.10;
	if (map[(int)(player->pos_y - player->dir_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_y * 0.10;
}

void	move_left(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x - player->plane_x * 0.10)] == '0')
		player->pos_x -= player->plane_x * 0.10;
	if (map[(int)(player->pos_y - player->plane_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->plane_y * 0.10;
}

void	move_right(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x + player->plane_x * 0.10)] == '0')
		player->pos_x += player->plane_x * 0.10;
	if (map[(int)(player->pos_y + player->plane_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y += player->plane_y * 0.10;
}