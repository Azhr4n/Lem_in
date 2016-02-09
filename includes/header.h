/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:38:53 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/03 15:38:54 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WROOM world->room
# define AI ft_atoi

# include "struct.h"

t_world		*create_world(void);
t_world		*set_world(int tab[2]);
void		set_pipe(t_world *world, char *str);
void		set_room(t_world *world, char *str);
void		set_world_ants(t_world *world, char *str);
int			set_room_command(t_world *world, char *str, int cmd, int tab[2]);

t_pipe		*new_pipe(t_pipe *pipe, t_room *room1, t_room *room2);
t_room		*new_room(t_room *room, char *name, int x, int y);
t_way		*new_way(t_way *way, t_room *room);
t_world		*create_world(void);

int			nb_room(t_room *room);

#endif
