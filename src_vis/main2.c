/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:50:58 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/28 16:51:02 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler2.h"

int		center(int n, char c, t_w *w)
{
	if (c == 'x')
		return ((WIDTH / 2) + (n - w->x / 2) * w->k);
	else if (c == 'y')
		return ((HEIGHT / 2) + (n - w->y / 2) * w->k);
	else
		return (0);
}

void	pixel(int x, int y, t_w *w)
{
	int		i;
	int		j;
	int		k;
	int		n;

	mlx_pixel_put(w->mlx_ptr, w->win_ptr, center(x, 'x', w), center(y, 'y', w),
		color(w->m[y][x], w));
	if (w->m[y][x] && w->m[y][x] != '.' && x != w->x && y != w->y &&
		!(i = 0))
		while (center(y, 'y', w) + i++ < center(y + 1, 'y', w) && !(j = 0))
			while (center(x, 'x', w) + j++ < center(x + 1, 'x', w))
				mlx_pixel_put(w->mlx_ptr, w->win_ptr,
					center(x, 'x', w) + j, center(y, 'y', w) + i,
					color(w->m[y][x], w));
	if (x != w->x && (k = -1))
		while (center(x, 'x', w) + k++ < center(x + 1, 'x', w))
			mlx_pixel_put(w->mlx_ptr, w->win_ptr,
				center(x, 'x', w) + k, center(y, 'y', w), 0x000000);
	if (y != w->y && (n = -1))
		while (center(y, 'y', w) + n++ < center(y + 1, 'y', w))
			mlx_pixel_put(w->mlx_ptr, w->win_ptr,
				center(x, 'x', w), center(y, 'y', w) + n, 0x000000);
}

void	window(t_w *w)
{
	int		i;
	int		j;
	char	*line;

	i = 8;
	get_next_line(0, &line);
	w->y = ft_my_atoi(line, &i);
	w->x = ft_my_atoi(line, &i);
	free(line);
	i = -1;
	w->m = (char **)malloc(sizeof(char *) * (w->y + 1));
	while (++i < w->y)
		w->m[i] = (char*)malloc(sizeof(char) * (w->x + 1));
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, WIDTH, HEIGHT, "vkozhemi.filler");
	w->k = fmin(WIDTH / (w->y + 1), HEIGHT / (w->x + 1));
	// paint(w);
}

void	ft_find_player(t_w *w)
{
	int i;
	char *line;

	i = 6;
	while (i--)
	{
		get_next_line(0, &line);
		free(line);
	}
	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
		w->play1 = ft_strdup(line + 14);
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	if (ft_strstr(line, "p2"))
		w->play2 = ft_strdup(line + 14);
	free(line);
	w->col1 = 0x0000ff;
	w->col2 = 0xff0000;
	w->col11 = 0x14FFEA;
	w->col22 = 0xFFD214;
}

int		main(int argc, char **argv)
{
	char		*line;
	t_w			*w;

	w = malloc(sizeof(t_w));
	ft_find_player(w);
	window(w);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "== X fin"))
		{
			free(line);
			exit(1);
		}
		if (ft_strstr(line, "Plateau"))
		{
			free(line);
			get_next_line(0, &line);
			free(line);
		}
		ft_save_map(w);
		ft_count_x_o(w);
		mlx_hook(w->win_ptr, 2, 5, hadle_imput_key, w);
		free(line);
		while (get_next_line(0, &line) > 0 && !ft_strstr(line, "Plateau"))
			free(line);
		
	}
	mlx_loop_hook(w->mlx_ptr, paint, w);
	mlx_loop(w->mlx_ptr);
	free(w);
	
	return (0);
}
