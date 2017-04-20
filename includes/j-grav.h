/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j-grav.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:37:29 by cyildiri          #+#    #+#             */
/*   Updated: 2017/04/19 16:39:28 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_GRAV_H
# define J_GRAV_H

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

#endif
