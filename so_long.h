/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:25:03 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/10 20:23:12 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		map_reading(t_complete *game, char **argv);
void	check_errors(t_complete *game);
void	if_walls(t_complete *game);
int		exit_point(t_complete *game);
void	character_valid(t_complete *game);
void	place_images_in_game(t_complete *game);
void	adding_in_graphics(t_complete *game);
int		controls_working(int command, t_complete *game);
int		right_move(t_complete *game, int i, int j);

#endif