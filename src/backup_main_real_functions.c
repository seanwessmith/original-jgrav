/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:20:36 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/09 21:44:46 by ssmith           ###   ########.fr       */
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
/*
	i = -1;
	while (++i < cluster->star_ct)
	{
		printf("%.0f ", cluster->stars[i].x);
		printf("%.0f ", cluster->stars[i].y);
		printf("%.0f", cluster->stars[i].z);
		printf("\n");
	}
	*/
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

double	find_force(t_stars one, t_stars two, double distance)
{
	double	force;

	force = one.mass * two.mass * (6.673 * pow(10.0, -11.0));
	printf("                     FORCE = %f\n", force);
	printf("                     DISTANCE = %f\n", pow(distance, 3));
	force /= pow(distance, 3);
	return (force);
}

double	find_distance(t_stars one, t_stars two)
{
	double	distance;

	distance = pow((one.x - two.x), 2) + pow((one.y - two.y), 2) +
		(one.z - two.z);
	return (distance);
}

void		calc_velocity(t_stars *one, t_stars *two)
{
	double	force;
	double	distance;

	distance = find_distance(*one, *two);
	force = find_force(*one, *two, distance);
	printf("                   FORCE2 = %f\n", force);
	one->deltax = (force * (one->x - two->x));
	one->deltay = (force * (one->y - two->y));
	one->deltaz = (force * (one->z - two->z));
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
		cluster->stars[i].x += cluster->stars[i].vx * time;
		cluster->stars[i].y += cluster->stars[i].vy * time;
		cluster->stars[i].z += cluster->stars[i].vz * time;
	}
}

void		init_stars(t_cluster *cluster, int stars_ct)
{
	int		i;
	float	mod;

	i = -1;
	mod = .001;
	while (++i < stars_ct)
	{
		cluster->stars[i].mass = ft_randint(5);
		cluster->stars[i].x = ft_randint(1) * mod;
		cluster->stars[i].y = ft_randint(1) * mod;
		cluster->stars[i].z = ft_randint(1) * mod;
		cluster->stars[i].velocity = ft_randint(1);
		cluster->stars[i].vx = ft_randint(1);
		cluster->stars[i].vy = ft_randint(1);
		cluster->stars[i].vz = ft_randint(1);
	}
}

int			main()
{
	int			i;
	t_cluster	cluster;

	i = 0;
	cluster = *(t_cluster *)malloc(sizeof(cluster));
	cluster.stars = (t_stars *)malloc(sizeof(t_stars) * 2);
	cluster.star_ct = 2;
	init_stars(&cluster, cluster.star_ct);
	while (i++ < 100)
	{
//		print_stars(&cluster, cluster.star_ct);
		calc_velocity(&cluster.stars[0], &cluster.stars[1]);
		calc_velocity(&cluster.stars[1], &cluster.stars[0]);
		apply_velocity(&cluster);
//		print_stars(&cluster, cluster.star_ct);
		print_output(&cluster);
	}
	return (0);
}
