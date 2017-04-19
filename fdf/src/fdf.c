/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 10:50:31 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 21:19:52 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/ft_printf.h"

void	mlx(t_fdf *fdf)
{
	printf("mlx\n");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "mlx 42");
	draw_line(fdf);
	mlx_key_hook(fdf->win, ft_key, fdf);
	mlx_loop(fdf->mlx);
}

int		main(int ac, char **av)
{
	int		fd;
	t_fdf	fdf;

	if (ac == 2)
	{
		fd = 0;
		init_fdf(&fdf);
		if (count(fd, av, &fdf) != -1)
		{
			if (malloc_fdf(fd, av, &fdf) != -1)
			{
				init_fdf(&fdf);
				mlx(&fdf);
			}
		}
		free(&fdf);
	}
	return (0);
}
