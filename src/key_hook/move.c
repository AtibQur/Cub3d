/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:05:59 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/06 14:46:46 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x + player->dir_x * 0.10)] == '0')
		player->pos_x += player->dir_x * 0.10;
	if (map[(int)(player->pos_y + player->dir_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_y * 0.10;
	printf("y = %f, x = %f \n", player->pos_y, player->pos_x);
}

void	move_backward(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x - player->dir_x * 0.10)] == '0')
		player->pos_x -= player->dir_x * 0.10;
	if (map[(int)(player->pos_y - player->dir_y * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_y * 0.10;
	printf("y = %f, x = %f \n", player->pos_y, player->pos_x);
}

void	move_right(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x - player->dir_y * 0.10)] == '0')
		player->pos_x -= player->dir_y * 0.10;
	if (map[(int)(player->pos_y + player->dir_x * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_x * 0.10;
		printf("y = %f, x = %f \n", player->pos_y, player->pos_x);
}

void	move_left(char **map, t_player *player)
{
	if (map[(int)(player->pos_y)][(int)(player->pos_x + player->dir_y * 0.10)] == '0')
		player->pos_x += player->dir_y * 0.10;
	if (map[(int)(player->pos_y + player->dir_x * 0.10)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_x * 0.10;
	printf("y = %f, x = %f \n", player->pos_y, player->pos_x);
}
