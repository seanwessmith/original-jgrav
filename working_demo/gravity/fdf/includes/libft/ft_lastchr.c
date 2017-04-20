/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:47:35 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/16 12:49:05 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	ft_lastchr(const char *str)
{
	char	ch;

	ch = *str;
	while (*str)
	{
		ch = *str;
		str++;
	}
	return (ch);
}
