/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:36:10 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/03 18:03:11 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "road_tools.h"
#include "checks.h"
#include "header.h"
#include "tools.h"
#include "ants.h"

static t_world	*make_world(void)
{
	t_world	*world;
	t_room	*start;
	t_room	*rstart;
	int		tab[2] = {0, 0};

	world = set_world(tab);
	if (!tab[0] || !tab[1] || !world->ants)
	{
		ft_putendl("ERROR : NO ANTS OR NO END OR START !");
		return (0);
	}
	else if (world->pipe == NULL)
	{
		ft_putendl("NO PIPE !");
		return (0);
	}
	start = get_start(world->room);
	rstart = world->room;
	while (rstart)
	{
		make_links(rstart, world->pipe);
		rstart = rstart->next;
	}
	return (world);
}

static int		make_beacon(t_world *world)
{
	int		len;
	int		len2;
	int		*tab;
	t_room	*start;

	len = nb_room(world->room);
	tab = (int *)malloc(sizeof(int) * len);
	tab = fill_tab_i(tab, 0, len);
	start = get_start(world->room);
	len2 = shortest_way(start, 0, tab);
	if (len2 < 1)
	{
		ft_putendl("NO WAY AVAILABLE !");
		return (0);
	}
	tab = fill_tab_i(tab, 0, len);
	beacon(start, len2, 0, tab);
	free(tab);
	return (1);
}

static void		gsw(t_room *start, int *tab, t_way *way)
{
	int		i;

	while (!start->end)
	{
		i = 0;
		while (start->links[i] && !start->end)
		{
			if (start->links[i]->g_road && !tab[start->links[i]->nb])
			{
				tab[start->links[i]->nb] = 1;
				way = new_way(way, start->links[i]);
				start = start->links[i];
			}
			i++;
		}
	}
}

static t_way	*get_shortest_way(t_world *world, t_way *way)
{
	t_room	*start;
	t_way	*sway;
	int		*tab;
	int		len;

	len = nb_room(world->room);
	tab = (int *)malloc(sizeof(int) * len);
	tab = fill_tab_i(tab, 0, len);
	start = get_start(world->room);
	way = new_way(way, start);
	sway = way;
	tab[start->nb] = 1;
	gsw(start, tab, way);
	free(tab);
	return (sway);
}

int				main(void)
{
	t_way	*way;
	t_ants	*ants;
	t_world	*world;

	world = make_world();
	if (!world)
		return (0);
	else if (!make_beacon(world))
		return (0);
	way = NULL;
	way = get_shortest_way(world, way);
	ants = chain_ants(world, way);
	moving_ants(world, ants, way);
	return (0);
}
