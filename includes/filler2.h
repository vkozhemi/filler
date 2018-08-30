/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:03:55 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 19:10:04 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER2_H
# define FILLER2_H

# include <stdio.h>
# include "../libftprintf/includes/libft.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/includes/printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# define HEIGHT 1200
# define WIDTH 2000

typedef struct		s_w
{
	char			**m;
	int				len_x;
	int				len_o;
	char			*play1;
	char			*play2;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	double			k;
	unsigned int	col1;
	unsigned int	col2;
	unsigned int	col11;
	unsigned int	col22;
}					t_w;

void				find_player(t_w *w);
void				window(t_w *w);
void				pixel(int x, int y, t_w *w);
int					center(int n, char c, t_w *w);
void				ft_count_x_o(t_w *w);
void				ft_save_map(t_w *w);
int					color(char c, t_w *w);
int					paint(t_w *w);
int					hadle_imput_key(int key, t_w *w);

#endif
