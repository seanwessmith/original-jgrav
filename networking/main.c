/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:48:39 by scollet           #+#    #+#             */
/*   Updated: 2017/05/05 18:48:45 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int   main(int ac, char **av)
{
  if (ac == 2)
  {
    if (!(strcmp(av[1], "1")))
      launch_dispatch();
    else
      launch_worker();
  }
  printf("Usage: ./executable [port #]\n");
  return (0);
}
