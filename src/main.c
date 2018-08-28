/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:54:30 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/19 15:54:32 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_map_piece(t_m *m, t_p *p)
{
	char	*line;
	int		i;

	line = NULL;
	ft_save_map(m, line);
	get_next_line(0, &line);
	if (ft_strncmp(line, "Piece", 4) == 0)
	{
		i = 5;
		p->p_size_y = ft_my_atoi(line, &i);
		p->p_size_x = ft_my_atoi(line, &i);
		ft_save_piece(p, line);
	}
	ft_count_x_o(m);
	ft_find_coord_x_o(m, p, 0, 0);
	ft_calc_distance_to_x_o(m, p, -1, 0);
	m->tmp_res = 0;
	m->i = malloc(sizeof(int) * (m->m_size_x * m->m_size_y));
	m->j = malloc(sizeof(int) * (m->m_size_y * m->m_size_x));
}

void	ft_check_all_place(t_m *m, t_p *p, int j, int l)
{
	int i;

	ft_restart_y(p);
	while (++j < m->m_size_y)
	{
		i = -1;
		m->k = 0;
		ft_restart_x(p);
		while (++i < m->m_size_x)
		{
			if ((ft_check_one_place(m, p)) == 1)
			{
				m->i[l] = i;
				m->j[l] = j;
				ft_check_square(m, p, &l);
				ft_choose_square(m, i, j);
				l++;
			}
			m->l = 0;
			while (m->l < p->c_s)
				p->s_x2[m->l++] += 1;
		}
		while (m->k < p->c_s)
			p->s_y2[m->k++] += 1;
	}
}

void	ft_check_square(t_m *m, t_p *p, int *l)
{
	int i;
	int j;
	int n;

	j = 0;
	n = 0;
	m->res = 0;
	while (j < m->m_size_y)
	{
		i = 0;
		while (i < m->m_size_x)
		{
			if (n < p->c_s && j == p->s_y[n] + m->j[*l] &&
				i == p->s_x[n] + m->i[*l])
			{
				m->res += m->md[j][i];
				n++;
			}
			i++;
		}
		j++;
	}
}

void	ft_choose_square(t_m *m, int i, int j)
{
	if (m->tmp_res == 0)
	{
		m->tmp_res = m->res;
		m->tmp_i = i;
		m->tmp_j = j;
	}
	else if (m->tmp_res > m->res)
	{
		m->tmp_i = i;
		m->tmp_j = j;
		m->tmp_res = m->res;
	}
}

int		main(void)
{
	t_m		*m;
	t_p		*p;
	char	*line;

	m = (t_m*)malloc(sizeof(*m));
	p = (t_p*)malloc(sizeof(*p));
	get_next_line(0, &line);
	p->pl = ft_atoi(line + 10);
	m->flag = 0;
	while (1)
	{
		get_next_line(0, &line);
		if (!m->flag)
		{
			ft_get_map_size(m, line);
			ft_allocate_map(m);
			m->flag = 1;
		}
		ft_get_map_piece(m, p);
		ft_check_all_place(m, p, -1, 0);
		ft_printf("%d %d\n", m->tmp_j - p->j_min, m->tmp_i - p->i_min);
	}
	free(m);
	free(p);
	return (0);
}
