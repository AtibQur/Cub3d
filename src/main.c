/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:46:09 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/05 16:00:08 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void    print_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i <= data->map.height)
    {
        j = 0;
        while (data->map.map[i][j])
        {
            printf("%c ", data->map.map[i][j]);
            j++;
        }
		printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
	t_data data;
	t_player player;

	init_game(&data, argc, argv);
	parse_map(&data);
	print_map(&data);
	player = init_player(&data);
	data.player = &player;
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
  	draw_floor_ceiling(&data);
  	draw_wall(&data);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
