/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j-grav.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:37:29 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/19 21:30:28 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_GRAV_H
# define J_GRAV_H
# include "mlx.h"
# include "libgraphics.h"

typedef struct		s_stars {
	double 			mass;
	double 			x;
	double 			y;
	double 			z;
	double 			vx;
	double			vy;
	double 			vz;
	double			deltax;
	double			deltay;
	double			deltaz;
}					t_stars;

typedef struct		s_cluster {
	t_stars			*stars;
	double 			star_ct;
}					t_cluster;

void        object_translation_controls(int keycode, t_renderer *renderer);
void        object_rotation_controls(int keycode, t_renderer *renderer);
void        camera_translation_controls(int keycode, t_renderer *renderer);
int         key_pressed(int keycode, void *param);
int         mouse_press_hook(int button, int x, int y, void *param);
int         mouse_release_hook(int button, int x, int y, void *param);
int         mouse_motion_hook(int x, int y, void *param);
void        center_obj_originxy(t_3d_object *object);
int         render_loop(void *param);
void        setup_hooks(t_renderer *renderer);

#endif
