/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 20:31:06 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 20:31:06 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "checks.h"
#include "header.h"
#include "tools.h"

void			set_world_ants(t_world *world, char *str)
{
	char	*tmp;

	tmp = del_space(str);
	world->ants = ft_atoi(tmp);
	free(tmp);
}

void			set_room(t_world *world, char *str)
{
	char	**tab;
	char	*tmp2;
	char	*tmp;

	tmp = del_space(str);
	tab = ft_strsplit(tmp, ' ');
	tmp2 = del_space(tab[0]);
	WROOM = new_room(WROOM, tmp2, AI(tab[1]), AI(tab[2]));
	free_tab(tab);
	free(tmp2);
	free(tmp);
}

int				set_room_command(t_world *world, char *str, int cmd, int tab[2])
{
	int		ret;

	free(str);
	ret = get_next_line(0, &str);
	if (str[0] == '\0')
		return (0);
	ft_putendl(str);
	if (check_room(str))
	{
		set_room(world, str);
		if (cmd == 1)
		{
			tab[0] = 1;
			world->room->start = 1;
		}
		if (cmd == 2)
		{
			tab[1] = 1;
			world->room->g_road = 1;
			world->room->end = 1;
		}
	}
	return (ret);
}

static t_room	*set_pipe_next(t_world *world, char *str)
{
	t_room	*start;
	t_room	*room;

	start = world->room;
	while (world->room)
	{
		if (ft_strcmp(world->room->name, str))
			room = world->room;
		world->room = world->room->next;
	}
	world->room = start;
	return (room);
}

void			set_pipe(t_world *world, char *str)
{
	t_room	*r1;
	t_room	*r2;
	char	**tab;
	char	*tmp;

	tmp = del_space(str);
	tab = ft_strsplit(tmp, '-');
	r1 = set_pipe_next(world, tab[0]);
	r2 = set_pipe_next(world, tab[1]);
	world->pipe = new_pipe(world->pipe, r1, r2);
	free_tab(tab);
	free(tmp);
}
