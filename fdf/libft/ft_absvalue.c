/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:41:01 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/23 15:41:45 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_absvalue(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}
