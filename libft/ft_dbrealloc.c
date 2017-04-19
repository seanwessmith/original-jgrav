/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbrealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:52:29 by ssmith            #+#    #+#             */
/*   Updated: 2016/12/18 12:30:24 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int		**ft_dbrealloc(int **ptr, size_t size, size_t size2)
{
	int		i;
	int		j;
    int		**ret;

	i = -1;
    ret = (int **)ft_memalloc(sizeof(int) * size);
	while (i++ < (int)size - 1)
	{
		j = size2;
		ret[i] = (int *)ft_memalloc(sizeof(int) * size2);
		while (--j > 0 && i < (int)size - 1)
			ft_memcpy(&ret[i][j], &ptr[i][j], sizeof(int));
	}
	if (ptr)
		free(ptr);
    return (ret);
}
