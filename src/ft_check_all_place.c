/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all_place.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:58:56 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/18 15:59:04 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_restart_x(t_p *p)
{
	int n;

	n = -1;
	p->s_x2 = malloc(sizeof(int) * (p->c_s));
	while (++n < p->c_s)
		p->s_x2[n] = p->s_x[n];
}

void	ft_restart_y(t_p *p)
{
	int n;

	n = -1;
	p->s_y2 = malloc(sizeof(int) * (p->c_s));
	while (++n < p->c_s)
		p->s_y2[n] = p->s_y[n];
}

void	ft_make_zero(t_m *m)
{
	m->n = 0;
	m->count_dots = 0;
	m->count_x = 0;
	m->count_o = 0;
}

int		ft_return_ok(t_m *m, t_p *p)
{
	if (p->pl == 1)
	{
		if (m->count_o == 1 && m->count_dots == p->c_s - 1 && !m->count_x)
			return (1);
	}
	else if (p->pl == 2)
	{
		if (m->count_x == 1 && m->count_dots == p->c_s - 1 && !m->count_o)
			return (1);
	}
	return (0);
}

int		ft_check_one_place(t_m *m, t_p *p)
{
	int i;
	int j;

	ft_make_zero(m);
	j = -1;
	while (++j < m->m_size_y)
	{
		i = -1;
		while (++i < m->m_size_x)
		{
			if (m->n < p->c_s && j == p->s_y2[m->n] && i == p->s_x2[m->n])
			{
				if (m->m[j][i] == 'x' || m->m[j][i] == 'X')
					m->count_x += 1;
				if (m->m[j][i] == '.')
					m->count_dots += 1;
				if (m->m[j][i] == 'o' || m->m[j][i] == 'O')
					m->count_o += 1;
				m->n++;
			}
		}
	}
	if (ft_return_ok(m, p) == 1)
		return (1);
	return (0);
}
