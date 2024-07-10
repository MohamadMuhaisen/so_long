/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:17:55 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/10 19:05:04 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_w(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 119)
		return (keyboard_w(game));
	else if (movement == 115)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 97)
		return (keyboard_a(game));
	else if (movement == 100)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 119 || command == 115)
		works = keyboard_w_s(game, command);
	if (command == 100 || command == 97)
		works = keyboard_a_d(game, command);
	if (command == 65307)
		exit_point(game);
	if (works)
		adding_in_graphics(game);
	return (1);
}
