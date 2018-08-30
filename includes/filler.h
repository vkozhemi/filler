/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:03:55 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 19:10:04 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "../libftprintf/includes/libft.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/includes/printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_m
{
	char			**m;
	int				**md;
	int				m_size_x;
	int				m_size_y;
	int				len_x;
	int				len_o;
	int				*x_x;
	int				*x_y;
	int				d_x;
	int				d_y;
	int				*d;
	int				count_x;
	int				count_dots;
	int				count_o;
	int				*i;
	int				*j;
	int				res;
	int				tmp_res;
	int				ii;
	int				jj;
	int				tmp_i;
	int				tmp_j;
	int				n;
	int				k;
	int				l;
	int				flag;
}					t_m;

typedef struct		s_p
{
	char			**p;
	int				p_size_x;
	int				p_size_y;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				c_s;
	int				*s_x;
	int				*s_y;
	int				*s_x2;
	int				*s_y2;
	int				i_min;
	int				j_min;
	int				pl;
	int				i;
	int				j;
}					t_p;

void				ft_find_player(t_p	*p);
void				ft_get_map_piece(t_m *m, t_p *p);
void				ft_check_all_place(t_m *m, t_p *p, int j, int l);
void				ft_place_x_o_on_map(t_m *m, t_p *p);
void				ft_calc_distance_to_x_o(t_m *m, t_p *p, int n, int k);
void				ft_find_coord_x_o(t_m *m, t_p *p, int i, int j);
void				ft_count_x_o(t_m *m);
void				ft_save_piece(t_p *p);
void				ft_stars_in_line(t_p *p);
void				ft_find_coord_stars(t_p *p);
void				ft_num_stars(t_p *p);
void				ft_save_map(t_m *m);
void				ft_get_piece_size(t_p *p);
void				ft_get_size_allocate_map(t_m *m);
void				ft_choose_square(t_m *m, int i, int j);
void				ft_check_square(t_m *m, t_p *p, int *l);
int					ft_check_one_place(t_m *m, t_p *p);
void				ft_restart_y(t_p *p);
void				ft_restart_x(t_p *p);

#endif
