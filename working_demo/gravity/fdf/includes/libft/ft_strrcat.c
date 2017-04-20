/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:38:00 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/22 20:34:54 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strrcat(char *s1, const char *s2, size_t start)
{
	size_t	x;
	size_t	i;

	x = 0;
	i = 0;
	while (s1[i] != '\0' && i < start)
		i++;
	while (s2[x] != '\0')
	{
		s1[i + x] = s2[x];
		x++;
	}
	s1[i + x] = '\0';
	return (s1);
}
