/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 20:06:16 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/23 20:06:20 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_get_size_allocate_map(t_m *m)
{
	int		i;
	int		j;
	int		k;
	char	*line;

	i = 8;
	get_next_line(0, &line);
	m->m_size_y = ft_my_atoi(line, &i);
	m->m_size_x = ft_my_atoi(line, &i);
	free(line);
	j = -1;
	m->m = (char **)malloc(sizeof(char *) * (m->m_size_y + 1));
	while (++j < m->m_size_y)
		m->m[j] = (char*)malloc(sizeof(char) * (m->m_size_x + 1));
	m->md = ft_memalloc(sizeof(int **) * m->m_size_y);
	k = -1;
	while (++k < m->m_size_y)
		m->md[k] = ft_memalloc(sizeof(int *) * m->m_size_x);
}

void	ft_save_map(t_m *m)
{
	int		i;
	char	*line;

	i = -1;
	get_next_line(0, &line);
	free(line);
	while (++i < m->m_size_y && get_next_line(0, &line))
	{
		ft_strcpy(m->m[i], line + 4);
		free(line);
	}
}

void	ft_count_x_o(t_m *m)
{
	int i;
	int j;

	m->len_x = 0;
	m->len_o = 0;
	j = 0;
	while (j < m->m_size_y)
	{
		i = 0;
		while (i < m->m_size_x)
		{
			if (m->m[j][i] == 'x' || m->m[j][i] == 'X')
				m->len_x++;
			if (m->m[j][i] == 'o' || m->m[j][i] == 'O')
				m->len_o++;
			i++;
		}
		j++;
	}
}

void	ft_find_player(t_p *p)
{
	char *line;

	get_next_line(0, &line);
	p->pl = ft_atoi(line + 10);
	free(line);
}
