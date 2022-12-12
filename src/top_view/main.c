/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:24:58 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/09 14:43:05 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int main()
{   
    t_map map;
    
    data_init(&map);
    draw_top_view_grid(&map);
    draw_player(&map);
    draw_direction(&map, map.posX, map.posY + 24);
	mlx_loop_hook(map.mlx, &player_hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	return (EXIT_SUCCESS);
}