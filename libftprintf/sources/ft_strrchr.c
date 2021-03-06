/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:15:59 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 18:56:53 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int j;

	j = 0;
	while (s[j] != '\0')
		j++;
	if (c == 0)
		return ((char *)s + j);
	while (j >= 0)
	{
		if (s[j] == c)
			return ((char *)s + j);
		j--;
	}
	return (0);
}
