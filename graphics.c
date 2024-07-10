/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:24 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/10 20:11:41 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

static void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/tile.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/item.xpm", &i, &j);
}

static void	parse(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 40, height * 40);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 40, height * 40);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			parse(game, height, width);
			width++;
		}
		height++;
	}
}
