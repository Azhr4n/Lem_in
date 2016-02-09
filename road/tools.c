/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 23:29:34 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/12 23:29:35 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "road_tools.h"
#include "tools.h"

t_room		*get_start(t_room *room)
{
	t_room	*start;

	start = room;
	while (start)
	{
		if (start->start)
			return (start);
		start = start->next;
	}
	return (0);
}

int			nb_links(t_pipe *pipe, t_room *room)
{
	t_pipe	*ps;
	int		inc;

	ps = pipe;
	inc = 0;
	while (ps)
	{
		if (ft_strcmp(ps->r1->name, room->name))
			inc++;
		else if (ft_strcmp(ps->r2->name, room->name))
			inc++;
		ps = ps->next;
	}
	return (inc);
}

void		make_links(t_room *room, t_pipe *pipe)
{
	t_pipe	*ps;
	int		len;

	ps = pipe;
	len = nb_links(pipe, room);
	if (!len)
		return ;
	room->links = (t_room **)malloc(sizeof(t_room *) * (len + 1));
	room->links[len] = NULL;
	len = 0;
	while (ps)
	{
		if (ft_strcmp(room->name, ps->r1->name))
		{
			room->links[len] = ps->r2;
			len++;
		}
		else if (ft_strcmp(room->name, ps->r2->name))
		{
			room->links[len] = ps->r1;
			len++;
		}
		ps = ps->next;
	}
}

int			shortest_way(t_room *room, int jumps, int *tab)
{
	static int	tmp = 0;
	int			i;

	if (!room->end)
	{
		i = 0;
		jumps++;
		tab[room->nb] = 1;
		while (room->links[i])
		{
			if (!tab[room->links[i]->nb])
				tmp = shortest_way(room->links[i], jumps, tab);
			i++;
		}
		tab[room->nb] = 0;
	}
	else
	{
		if (jumps < tmp || tmp == 0)
			return (jumps);
		else
			return (tmp);
	}
	jumps--;
	return (tmp);
}

void		beacon(t_room *room, int nb_max, int jumps, int *tab)
{
	int			i;

	if (jumps < nb_max)
	{
		i = 0;
		jumps++;
		while (room->links[i])
		{
			tab[room->nb] = 1;
			if (!tab[room->links[i]->nb])
				beacon(room->links[i], nb_max, jumps, tab);
			if (room->links[i]->g_road && !room->links[i]->g_road_used
				&& !tab[room->links[i]->nb])
			{
				room->links[i]->g_road_used = 1;
				room->g_road = 1;
			}
			i++;
		}
		tab[room->nb] = 0;
	}
	jumps--;
}
