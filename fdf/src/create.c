/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:57:47 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 20:33:30 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/ft_printf.h"

int		ft_count(char *str)
{
	int		count;
	char	last;

	last = 0;
	count = (*str != ' ') ? 1 : 0;
	str++;
	while (*str)
	{
		if (*str != ' ' && last == ' ')
			count++;
		last = *str;
		str++;
	}
	return (count);
}

int		ft_parse_nbr(char *str, int *in_ct)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '-')
		{
			sign = 1;
			i++;
		}
		*in_ct = (*in_ct * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		*in_ct *= -1;
	return (i);
}

void	ft_parse(char *line, t_fdf *fdf, int x)
{
	int		ret;
	int		y;

	y = 0;
	ret = 0;
	while (ret + 1 < (int)ft_strlen(line))
	{
		fdf->in[x][y] = 0;
		ret += ft_parse_nbr(line + ret, &fdf->in[x][y]);
		y++;
	}
}

int		malloc_fdf(int fd, char **av, t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	fdf->in_ct = (int **)malloc(sizeof(int *) * fdf->rows);
	fdf->in = (int **)malloc(sizeof(int *) * fdf->rows);
	while (get_next_line(fd, &line) > 0)
	{
		j = fdf->cols;
		k = 0;
		fdf->in_ct[i] = (int *)ft_memalloc(sizeof(int) * 3);
		fdf->in[i] = (int *)ft_memalloc(sizeof(int) * 3);
		ft_parse(line, fdf, i);
		i++;
	}
	close(fd);
	return (0);
}
