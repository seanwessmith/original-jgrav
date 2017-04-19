/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:58:37 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 21:25:16 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/libft/includes/ft_printf.h"

void    draw_point(t_fdf *fdf, int x, int y)
{
    int                i;
    unsigned int    color;

	color = 0xFFFFFF;
    if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
    {
        i = (x * 4) + (y * fdf->lsize);
        fdf->pix_map[i] = fdf->color;
		fdf->pix_map[++i] = fdf->color >> 8;
		fdf->pix_map[++i] = fdf->color >> 16;
    }
}

int		count(int fd, char **av, t_fdf *fdf)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line))
		fdf->rows++;
	close(fd);
	return (0);
}

void	init_fdf(t_fdf *fdf)
{
	if (!fdf->rows || !fdf->cols)
	{
		fdf->rows = 0;
		fdf->cols = 0;
	}
	fdf->scale = (fdf->rows > fdf->cols) ?
		((float)WIN_H / 1.5) / ((float)fdf->rows)
		: ((float)WIN_W / 1.5) / ((float)fdf->cols);
	fdf->centery = (WIN_W - ((fdf->cols) * fdf->scale)) / 2;
	fdf->centerx = (WIN_H - ((fdf->rows) * fdf->scale)) / 2;
}

void	draw_line(t_fdf *fdf)
{
	int		x;
	int		i;
	int		ed;
	int		bpp;

	i = -1;
	fdf->color = 0xFFFFFF;
    fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
    fdf->pix_map = mlx_get_data_addr(fdf->img, &bpp, &(fdf->lsize), &ed);
	while (++i < fdf->rows)
	{
		x = 0;
		printf("i %d\n", i);
		draw_point(fdf, fdf->in[i][0], fdf->in[i][1]);
//		mlx_pixel_put(fdf->mlx, fdf->win, fdf->in[i][0],
//				fdf->in[i][2], fdf->color);
	    if (i % 2 && i > 50)
		{	
			mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
			fdf->color -= (i / 100);
			usleep(1000);
		}
	}
}
