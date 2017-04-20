/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:59:16 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 20:47:51 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/ft_printf.h"

int		ft_key(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	if (keycode == 1)
		fdf->centerx += 50;
	else if (keycode == 13)
		fdf->centerx -= 50;
	else if (keycode == 2)
		fdf->centery += 50;
	else if (keycode == 0)
		fdf->centery -= 50;
	mlx_clear_window(fdf->mlx, fdf->win);
	return (0);
}
