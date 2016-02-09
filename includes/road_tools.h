/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 23:30:16 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/12 23:30:18 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROAD_TOOLS_H
# define ROAD_TOOLS_H

# include "struct.h"

t_room		*get_start(t_room *room);
int			nb_links(t_pipe *pipe, t_room *room);
void		make_links(t_room *room, t_pipe *pipe);
int			shortest_way(t_room *room, int jumps, int *tab);
void		beacon(t_room *room, int nb_max, int jumps, int *tab);

#endif
