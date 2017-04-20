/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:52:29 by ssmith            #+#    #+#             */
/*   Updated: 2016/12/18 12:30:24 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_realloc(char *ptr, size_t size)
{
    char	*str;
   	if (ptr)
    	str = (char *)malloc(size * ft_strlen(ptr));
	else
    	str = (char *)malloc(size);
    ft_memcpy(str, ptr, ft_strlen(ptr) + 1);
	if (ptr)
		free(ptr);
    return (str);
}
