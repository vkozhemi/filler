/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 20:06:16 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/23 20:06:20 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler2.h"

void	ft_save_map(t_w *w)
{
	int i;
	char *line;

	i = -1;
	paint(w);
	while (++i < w->y && get_next_line(0, &line))
	{
		ft_strcpy(w->m[i], line + 4);
		free(line);
	}
}

void	ft_count_x_o(t_w *w)
{
	int i;
	int j;

	w->len_x = 0;
	w->len_o = 0;
	j = 0;
	while (j < w->y)
	{
		i = 0;
		while (i < w->x)
		{
			if (w->m[j][i] == 'x' || w->m[j][i] == 'X')
				w->len_x++;
			if (w->m[j][i] == 'o' || w->m[j][i] == 'O')
				w->len_o++;
			i++;
		}
		j++;
	}
}

int		color(char c, t_w *w)
{
	if (c == 'O')
		return (w->col1);
	else if (c == 'o')
		return (w->col11);
	else if (c == 'X')
		return (w->col2);
	else if (c == 'x')
		return (w->col22);
	else
		return (0xffffff);
}

int		paint(t_w *w)
{
	int		y;
	int		x;
	char	*len_o;
	char	*len_x;

	y = -1;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	while (++y < w->y && (x = -1))
		while (++x < w->x)
			pixel(x, y, w);
	// if (len_o)
	// 	free(len_o);
	// if (len_x)
	// 	free(len_x);
	len_o = ft_itoa(w->len_o);
	len_x = ft_itoa(w->len_x);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 50, 0x33FFFF, "HELP");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 100, 0x33FFFF, "exit: esc");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 125, 0x33FFFF, "color: 1");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 1050, w->col1, w->play1);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 300, 1050, w->col1, len_o);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 1100, w->col2, w->play2);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 300, 1100, w->col2, len_x);
	mlx_do_sync(w->mlx_ptr);
	return (1);
}

int		hadle_imput_key(int key, t_w *w)
{
	if (key == 53)
		exit(1);
	if (key == 18)
	{
		w->col1 += 1000;
		w->col2 += 1000;
		w->col11 += 1000;
		w->col22 += 1000;
		if (w->col1 > 0xffffff)
			w->col1 = 0x0000ff;
		if (w->col2 > 0xffffff)
			w->col2 = 0xff0000;
		if (w->col11 > 0xffffff)
			w->col11 = 0x14FFEA;
		if (w->col22 > 0xffffff)
			w->col22 = 0xFFD214;
	}
	return (0);
}
