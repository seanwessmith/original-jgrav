/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:20:36 by ssmith            #+#    #+#             */
/*   Updated: 2017/04/23 16:51:58 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "j-grav.h"

/*
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
*/
double	find_distance(t_stars one, t_stars two)
{
	double	distance;

	distance = sqrt(pow(two.x - one.x, 2) + pow(two.y - one.y, 2) + pow(two.z - one.z, 2));
	return (distance);
}

double	find_force(double b_mass, double b_dist, double a_dist, double distance)
{
	double	force;

//ORIGINAL	force = (a_mass * (6.673 * pow(10, -11) / pow(distance, 3)) * (b_dist - a_dist));
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
		////////////////////////////////////////////////////////////
	}
}

void		init_stars(t_cluster *cluster, int stars_ct)
{
	int		i;

	i = -1;
	while (++i < stars_ct)
	{
		cluster->stars[i].mass = ft_randint(10);
		///TEMPORARY
		cluster->stars[0].mass = 5.972 * pow(10, 24);
		cluster->stars[1].mass = 419600;
		//X Y & Z are hardcoded, needs to be changed to rand(x)
		cluster->stars[0].x = 200;
		cluster->stars[0].y = 200;
		cluster->stars[0].z = 200;
		cluster->stars[1].x = 400;
		cluster->stars[1].y = 400;
		cluster->stars[1].z = 400;
		//TEMPORARY
		cluster->stars[0].vx = 0;
		cluster->stars[0].vy = 0;
		cluster->stars[0].vz = 0;
		cluster->stars[1].vx = 1000000;
		cluster->stars[1].vy = 100000;
		cluster->stars[1].vz = 0;
		
	}
}

/*
**	Event Hook for rendering
*/

int			render_loop(t_env  *env)
{
	t_3d_object *point_map;
	int	i;

	//ft_putstr("p2\n");
	calc_velocity(&env->cluster->stars[0], &env->cluster->stars[1]);
	calc_velocity(&env->cluster->stars[1], &env->cluster->stars[0]);
	apply_velocity(env->cluster);

	point_map = (t_3d_object *)env->renderer->scene->objects->content;

	i = 0;
	//ft_putstr("p2\n");
	while (i < env->cluster->star_ct)
	{
		//ft_putstr("p3\n");
		//point_map_add_point(point_map, vec3fc(5, 5, 5, 0x00FF0000));
		//point_map_add_point(point_map, vec3fc(5, 10, 5, 0x000000FF));
		//point_map_add_point(point_map, vec3fc(10, 5, 5, 0x000000FF));
		//point_map_add_point(point_map, vec3fc(10, 10, 5, 0x000000FF));
        //point_map_add_point(point_map, vec3fc(5, 5, 10, 0x00FF0000));
    	//point_map_add_point(point_map, vec3fc(5, 10, 10, 0x000000FF));
        //point_map_add_point(point_map, vec3fc(10, 5, 10, 0x000000FF));
    	//point_map_add_point(point_map, vec3fc(10, 10, 10, 0x000000FF));
		point_map_add_point(point_map, vec3fc(env->cluster->stars[i].x,
                                              env->cluster->stars[i].y,
                                              env->cluster->stars[i].z,
                                              blend(0x00FF0000, 0x00FFFFFF, (time(NULL) % 60) / 60.0f )));
        printf("time: %f\n", (time(NULL) % 60) / 60.0f );
		i++;
		//ft_putstr("p4\n");
	}
	//ft_putstr("p5\n");
	env->renderer->render(env->renderer, *env->renderer->scene);
	//ft_putstr("p6\n");
	return (0);
}

/*
**	Set all the event hooks
*/

void		setup_hooks(t_renderer *renderer, t_env *env)
{
	mlx_hook(renderer->window, 2, 0, key_pressed, renderer);
	mlx_hook(renderer->window, 4, 0, mouse_press_hook, renderer);
	mlx_hook(renderer->window, 5, 0, mouse_release_hook,renderer);
	mlx_hook(renderer->window, 6, 0, mouse_motion_hook, renderer);
	mlx_loop_hook(renderer->mlx, render_loop, env);
	mlx_loop(renderer->mlx);
}

#include <stdio.h>

int			main()
{
	t_env		env;
	int			i;
	t_cluster	cluster;
	t_renderer	*renderer;
	t_scene		*scene1;
	t_3d_object *point_map;

	i = 0;
	renderer = new_renderer(scene_render_point_map);
	printf(" %p \n", renderer);
	add_window(renderer, 1000, 1000, "two body gravity simulation");
	scene1 = new_scene(perspective_projection, 1000, 1000);
	scene1->camera = new_camera(vec6f(vec3f(0, 0, 1700), vec3f(0.139000, -0.176000, 0.000000)), vec3f(0, 0, 4));
	cluster = *(t_cluster *)malloc(sizeof(cluster));
	cluster.stars = (t_stars *)malloc(sizeof(t_stars) * 2);
	cluster.star_ct = 2;
	init_stars(&cluster, cluster.star_ct);
	point_map = new_point_map(1000000);
//	point_map_add_point(point_map, vec3fc(-2.5, -2.5, -2.5, 0x00FF0000));
//	point_map_add_point(point_map, vec3fc(-2.5, 2.5, -2.5, 0x000000FF));
//	point_map_add_point(point_map, vec3fc(2.5, -2.5, -2.5, 0x000000FF));
//	point_map_add_point(point_map, vec3fc(2.5, 2.5, -2.5, 0x000000FF));
//	point_map_add_point(point_map, vec3fc(-2.5, -2.5, 2.5, 0x00FF0000));
//	point_map_add_point(point_map, vec3fc(-2.5, 2.5, 2.5, 0x000000FF));
//	point_map_add_point(point_map, vec3fc(2.5, -2.5, 2.5, 0x000000FF));
//	point_map_add_point(point_map, vec3fc(2.5, 2.5, 2.5, 0x000000FF));
	point_map->pos_vector.position = vec3f(0.0, 0.0, 0.0);
	point_map->pos_vector.rotation = vec3f(0.0, 0.0, 0.0);
	//center_obj_originxy(point_map);
	add_object(scene1, point_map);
	scene1->active_obj = 0;
	scene1->origin_point = vec3f(0, 0, 0);
	renderer->scene = scene1;
	env.cluster = &cluster;
	env.renderer = renderer;
	setup_hooks(renderer, &env);
	return (0);
}
