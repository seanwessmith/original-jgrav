/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:20:36 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 22:26:42 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "../libft/includes/libft.h"
#include <math.h>

void		print_output(t_cluster *cluster)
{
	int		i;
	i = 0;
		printf("%.0f ", cluster->stars[i].x);
		printf("%.0f ", cluster->stars[i].y);
		printf("%.0f", cluster->stars[i].z);
		printf("\n");
	i = -1;
	while (++i < cluster->star_ct)
	{
    printf("i%d\n", i)
		printf("%.0f ", cluster->stars[i].x);
		printf("%.0f ", cluster->stars[i].y);
		printf("%.0f", cluster->stars[i].z);
		printf("\n");
	}
}

void		print_stars(t_cluster *cluster, int stars_ct)
{
	int		i;

	i = -1;
  while (++i < stars_ct)
	{
		printf("stars[%d]:\n", stars_ct);
		printf("mass: %f\n", cluster->stars[i].mass);
		printf("x: %f\n", cluster->stars[i].x);
		printf("y: %f\n", cluster->stars[i].y);
		printf("z: %f\n", cluster->stars[i].z);
		printf("velocity: %f\n", cluster->stars[i].velocity);
		printf("vx: %f\n", cluster->stars[i].vx);
		printf("vy: %f\n", cluster->stars[i].vy);
		printf("vz: %f\n", cluster->stars[i].vz);
		printf("\n");
	}
}

double	find_distance(t_stars one, t_stars two)
{
	double	distance;

	distance = pow((two.x - one.x), 2) + pow((two.y - one.y), 2) +
		pow((two.z - one.z), 2);
	return (distance);
}

double	find_force(t_stars one, t_stars two, double distance)
{
	double	force;

	force = one.mass * two.mass * (6.673 * pow(10.0, -11.0));
//	printf("                    FORCE1 %f\n", force);
	force /= distance * .5;
	return (force);
}

void		calc_velocity(t_stars *one, t_stars *two)
{
	double	force;
	double	distance;

	distance = find_distance(*one, *two);
//	printf("                   DISTANCE = %f\n", distance);
	force = find_force(*one, *two, distance);
//	printf("                   FORCE = %f\n", force);
//	printf("                   two-x = %f\n", two->x);
//	printf("                   one-x = %f\n", one->x);
	one->deltax = (force * (two->x - one->x));
	one->deltay = (force * (two->y - one->y));
	one->deltaz = (force * (two->z - one->z));
//	printf("                   DELTAX = %f\n", one->deltax);
//	printf("                   DELTAY =%f\n", one->deltay);
//	printf("                   DELTAZ = %f\n", one->deltaz);
}

void		apply_velocity(t_cluster *cluster)
{
	int		i;
	double	time;

	i = -1;
	time = 1;
	while (++i < cluster->star_ct)
	{
		cluster->stars[i].vx += cluster->stars[i].deltax;
		cluster->stars[i].vy += cluster->stars[i].deltay;
		cluster->stars[i].vz += cluster->stars[i].deltaz;
//	printf("                   velocityx = %f\n", cluster->stars[i].vx);
//	printf("                   velocityy = %f\n", cluster->stars[i].vy);
//  printf("                   velocityz = %f\n", cluster->stars[i].vz);
		cluster->stars[i].x += cluster->stars[i].vx * time;
		cluster->stars[i].y += cluster->stars[i].vy * time;
		cluster->stars[i].z += cluster->stars[i].vz * time;
	}
}

void		init_stars(t_cluster *cluster, int stars_ct)
{
	int		i;
	float	mod;

  stars_ct = 0;
	i = -1;
	mod = 1;
  cluster->stars[0].mass = 5.972 + pow(10, 24);
	cluster->stars[0].x = 0;
	cluster->stars[0].y = 0;
	cluster->stars[0].z = 0;
	cluster->stars[0].velocity = ft_randint(1);
	cluster->stars[0].vx = 0;
	cluster->stars[0].vy = 0;
	cluster->stars[0].vz = 0;

  cluster->stars[1].mass = 419600;
	cluster->stars[1].x = 70;
	cluster->stars[1].y = 70;
	cluster->stars[1].z = 250000;
	cluster->stars[1].velocity = 7670;
	cluster->stars[1].vx = 7670;
	cluster->stars[1].vy = 0;
	cluster->stars[1].vz = 0;
}

int			main()
{
	int			i;
	t_cluster	cluster;

	i = 0;
	cluster = *(t_cluster *)malloc(sizeof(cluster));
	cluster.stars = (t_stars *)malloc(sizeof(t_stars) * 2);
	cluster.star_ct = 3;
	init_stars(&cluster, cluster.star_ct);
	while (i++ < 100)
	{
//		print_stars(&cluster, cluster.star_ct);
		calc_velocity(&cluster.stars[0], &cluster.stars[1]);
		apply_velocity(&cluster);
//		print_stars(&cluster, cluster.star_ct);
		print_output(&cluster);
	}
	return (0);
}
