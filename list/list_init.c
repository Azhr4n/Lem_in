/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:08:43 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/05 15:08:44 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"
#include "checks.h"
#include "tools.h"

t_world		*create_world(void)
{
	t_world	*world;

	world = (t_world*)malloc(sizeof(t_world));
	world->room = NULL;
	world->pipe = NULL;
	world->ants = 0;
	return (world);
}

t_world		*set_world(int tab[2])
{
	t_world	*world;
	char	*line;
	int		cmd;
	int		ret;

	world = create_world();
	ret = 1;
	while (get_next_line(0, &line) && ret != 0)
	{
		if (line[0] == '\0')
			return (world);
		ft_putendl(line);
		if (check_param_ants(line))
			set_world_ants(world, line);
		else if ((cmd = check_command(line)))
			ret = set_room_command(world, line, cmd, tab);
		else if (check_room(line))
			set_room(world, line);
		else if (check_pipe(line, world->room))
			set_pipe(world, line);
		free(line);
	}
	ft_putchar('\n');
	return (world);
}

t_room		*new_room(t_room *room, char *name, int x, int y)
{
	t_room	*n_room;

	n_room = (t_room*)malloc(sizeof(t_room));
	if (room)
		n_room->next = room;
	else
		n_room->next = NULL;
	n_room->name = ft_strcdup(name, '\0');
	n_room->links = NULL;
	n_room->g_road = 0;
	n_room->g_road_used = 0;
	n_room->start = 0;
	n_room->end = 0;
	n_room->x = x;
	n_room->y = y;
	return (n_room);
}

t_pipe		*new_pipe(t_pipe *pipe, t_room *room1, t_room *room2)
{
	t_pipe	*n_pipe;

	n_pipe = (t_pipe *)malloc(sizeof(t_pipe));
	if (pipe)
		n_pipe->next = pipe;
	else
		n_pipe->next = NULL;
	n_pipe->r1 = room1;
	n_pipe->r2 = room2;
	return (n_pipe);
}

t_way		*new_way(t_way *way, t_room *room)
{
	t_way	*n_way;

	n_way = (t_way *)malloc(sizeof(t_way));
	n_way->room = room;
	n_way->next = NULL;
	if (way)
		way->next = n_way;
	return (n_way);
}
