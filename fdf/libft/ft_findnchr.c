/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:01:55 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/05 22:11:40 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_findnchr(const char *s, int c, int start, int end)
{
	int		i;

	if (start < 0)
		start = 0;
	i = start;
	while (*s && i > 0)
	{
		i--;
		s++;
	}
	while (*s && *s != c && start < end)
	{
		start++;
		s++;
	}
	if (*s == '\0' || start == end)
		return (0);
	return (1);
}
