/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_basel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:28:01 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/04 14:27:56 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_basel(unsigned long long value, long base)
{
	long				len;
	unsigned long long	v;
	char				*str;

	if (base < 2 || base > 16)
		return (0);
	len = 1;
	v = value;
	while (v /= base)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[0] = '-';
	str[len] = 0;
	while (len-- > 0)
	{
		v = value % base;
		str[len] = (v > 9) ? v + 'A' - 10 : v + '0';
		value /= base;
	}
	return (str);
}
