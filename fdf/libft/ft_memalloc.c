/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:05:58 by ssmith            #+#    #+#             */
/*   Updated: 2016/12/17 19:45:42 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	str = (void *)malloc(sizeof(void) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
