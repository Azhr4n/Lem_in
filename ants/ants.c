/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 23:25:48 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 23:25:48 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "tools.h"
#include "ants.h"

t_ants		*new_ants(t_ants *ants, t_way *way, int nb)
{
	t_ants	*n_ants;

	n_ants = (t_ants *)malloc(sizeof(t_ants));
	n_ants->name = nb;
	n_ants->way = way;
	n_ants->next = NULL;
	if (ants)
		ants->next = n_ants;
	return (n_ants);
}

t_ants		*chain_ants(t_world *world, t_way *way)
{
	t_ants	*f_ants;
	t_ants	*ants;
	int		i;

	ants = NULL;
	ants = new_ants(ants, way, 1);
	f_ants = ants;
	i = 2;
	while (i <= world->ants)
	{
		ants = new_ants(ants, way, i);
		i++;
	}
	return (f_ants);
}

int			len_way(t_way *way)
{
	t_way	*sway;
	int		i;

	i = 0;
	sway = way;
	while (sway)
	{
		sway = sway->next;
		i++;
	}
	return (i);
}

void		print_ant(t_ants *ants)
{
	ft_putstr("L");
	ft_putnbr(ants->name);
	ft_putchar('-');
	ft_putstr(ants->way->room->name);
	ft_putchar(' ');
}

void		moving_ants(t_world *world, t_ants *ants, t_way *way)
{
	t_ants	*first_ants;
	int		len;
	int		i;
	int		j;

	i = 1;
	first_ants = ants;
	len = world->ants + len_way(way) - 1;
	while (i < len)
	{
		j = 0;
		while (ants && j < i)
		{
			if (ants && ants->way->next)
			{
				ants->way = ants->way->next;
				print_ant(ants);
			}
			ants = ants->next;
			j++;
		}
		ft_putchar('\n');
		i++;
		ants = first_ants;
	}
}
