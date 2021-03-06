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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../libft/includes/libft.h"
#include <math.h>

void		print_output(t_cluster *cluster)
{
	int		i;

	i = 0;
	while (++i < 2)
	{
		printf("%.0f ", cluster->stars[i].x);
		printf("%.0f ", cluster->stars[i].y);
		printf("%.0f", cluster->stars[i].z);
		printf("\n");
	}
}

double	find_distance(t_stars one, t_stars two)
{
	double	distance;

	distance = sqrt(pow(two.x - one.x, 2) + pow(two.y - one.y, 2) + pow(two.z - one.z, 2));
	return (distance);
}

double	find_force(double b_mass, double b_dist, double a_dist, double distance)
{
	double	force;

	force = ((b_mass * (6.673 * pow(10, -11) / pow(distance, 3))) * (b_dist - a_dist));
//	printf("                    force: %f\n", force);
	return (force);
}

void		calc_velocity(t_stars *one, t_stars *two)
{
	double	delta_t;
	double	distance;

	delta_t = .0000001;
	distance = find_distance(*one, *two);
	one->deltax = find_force(two->mass, two->x, one->x, distance) * delta_t;
	one->deltay = find_force(two->mass, two->y, one->y, distance) * delta_t;
	one->deltaz = find_force(two->mass, two->z, one->z, distance) * delta_t;
//	printf("                   DELTAX = %f\n", one->deltax);
///	printf("                   DELTAY =%f\n", one->deltay);
//	printf("                   DELTAZ = %f\n", one->deltaz);
}

void		apply_velocity(t_cluster *cluster)
{
	int		i;
	double	delta_t;

	delta_t = .0000001;
	i = -1;
	while (++i < cluster->star_ct)
	{
		cluster->stars[i].vx += cluster->stars[i].deltax;
		cluster->stars[i].vy += cluster->stars[i].deltay;
		cluster->stars[i].vz += cluster->stars[i].deltaz;
//		printf("velocityx = %f\n", cluster->stars[i].vx * delta_t);
//		printf("velocityy = %f\n", cluster->stars[i].vy * delta_t);
//		printf("velocityz = %f\n", cluster->stars[i].vz * delta_t);
		cluster->stars[i].x += cluster->stars[i].vx * delta_t;
		cluster->stars[i].y += cluster->stars[i].vy * delta_t;
		cluster->stars[i].z += cluster->stars[i].vz * delta_t;
	}
}

void		init_stars(t_cluster *cluster, int stars_ct)
{
	int		i;

	i = -1;
	while (++i < stars_ct)
	{
		cluster->stars[i].mass = ft_randint(10);
		cluster->stars[0].mass = 5.972 * pow(10, 24);
		cluster->stars[1].mass = 419600;
		//X Y & Z are hardcoded, needs to be changed to rand(x)
		cluster->stars[0].x = 200;
		cluster->stars[0].y = 200;
		cluster->stars[0].z = 200;
		cluster->stars[1].x = 400;
		cluster->stars[1].y = 400;
		cluster->stars[1].z = 400;
		cluster->stars[0].vx = 0;
		cluster->stars[0].vy = 0;
		cluster->stars[0].vz = 0;
		cluster->stars[1].vx = 1000000;
		cluster->stars[1].vy = 100000;
		cluster->stars[1].vz = 0;
		
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

	printf("%.0f ", cluster.stars[0].x);
	printf("%.0f ", cluster.stars[0].y);
	printf("%.0f\n", cluster.stars[0].z);
	while (i++ < 100000)
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
