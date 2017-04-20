/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 22:09:43 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/05 10:26:25 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	while (len > 0 && *src != '\0')
	{
		*s++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*s++ = '\0';
		len--;
	}
	return (dst);
}
