/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:52:29 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/20 15:07:53 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_realloc(char *ptr, size_t size)
{
	char	*str;

	if (ptr)
		str = (char *)malloc(size + ft_strlen(ptr));
	else
		str = (char *)malloc(size);
	ft_bzero(str, size);
	ft_memcpy(str, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (str);
}
