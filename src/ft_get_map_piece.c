/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:13:26 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/18 16:13:28 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_num_stars(t_p *p)
{
	int i;
	int j;

	p->i_min = p->p_size_x;
	p->j_min = p->p_size_y;
	p->c_s = 0;
	j = 0;
	while (j < p->p_size_y)
	{
		i = 0;
		while (i < p->p_size_x)
		{
			if (p->p[j][i] == '*')
			{
				p->c_s++;
				if (p->i_min > i)
					p->i_min = i;
				if (p->j_min > j)
					p->j_min = j;
			}
			i++;
		}
		j++;
	}
}

void	ft_find_coord_stars(t_p *p)
{
	int i;
	int j;
	int n;

	p->s_x = malloc(sizeof(int) * (p->c_s));
	p->s_y = malloc(sizeof(int) * (p->c_s));
	n = 0;
	j = 0;
	while (j < p->p_size_y)
	{
		i = 0;
		while (i < p->p_size_x)
		{
			if (p->p[j][i] == '*')
			{
				p->s_x[n] = i - p->i_min;
				p->s_y[n] = j - p->j_min;
				n++;
			}
			i++;
		}
		j++;
	}
}

void	ft_save_piece(t_p *p)
{
	int		j;
	char	*line;

	j = 0;
	p->p = (char **)malloc(sizeof(char *) * (p->p_size_y + 1));
	while (j < p->p_size_y && get_next_line(0, &line))
	{
		p->p[j++] = ft_strdup(line);
		if (line && *line)
			free(line);
	}
	ft_num_stars(p);
	ft_find_coord_stars(p);
}

void	ft_find_coord_x_o(t_m *m, t_p *p, int i, int j)
{
	int n;
	int k;

	k = (p->pl == 1) ? m->len_x : m->len_o;
	m->x_x = malloc(sizeof(int) * (k));
	m->x_y = malloc(sizeof(int) * (k));
	n = 0;
	j = -1;
	while (++j < m->m_size_y)
	{
		i = -1;
		while (++i < m->m_size_x)
		{
			if (p->pl == 1 && (m->m[j][i] == 'x' || m->m[j][i] == 'X'))
			{
				m->x_x[n] = i;
				m->x_y[n++] = j;
			}
			else if (p->pl == 2 && (m->m[j][i] == 'o' || m->m[j][i] == 'O'))
			{
				m->x_x[n] = i;
				m->x_y[n++] = j;
			}
		}
	}
}

void	ft_calc_distance_to_x_o(t_m *m, t_p *p, int n, int k)
{
	int i;
	int j;

	k = (p->pl == 1) ? m->len_x : m->len_o;
	m->d = malloc(sizeof(int) * (k));
	while (++n < k)
	{
		j = -1;
		while (++j < m->m_size_y)
		{
			i = -1;
			while (++i < m->m_size_x)
			{
				m->d_y = ft_abs(j - m->x_y[n]);
				m->d_x = ft_abs(i - m->x_x[n]);
				m->d[n] = (m->d_y > m->d_x) ? m->d_y : m->d_x;
				if (m->md[j][i] > m->d[n] || !m->md[j][i])
					m->md[j][i] = m->d[n];
				if (m->m[j][i] == 'x' || m->m[j][i] == 'X')
					m->md[j][i] = 0;
				if (m->m[j][i] == 'o' || m->m[j][i] == 'O')
					m->md[j][i] = 0;
			}
		}
	}
}
