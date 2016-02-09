/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 23:35:23 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/12 23:35:25 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_room
{
	int				x;
	int				y;
	int				start;
	int				end;
	int				nb;
	int				g_road;
	int				g_road_used;
	char			*name;
	struct s_room	*next;
	struct s_room	**links;
}					t_room;

typedef struct		s_pipe
{
	t_room			*r1;
	t_room			*r2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_world
{
	int				ants;
	t_room			*room;
	t_pipe			*pipe;
}					t_world;

typedef struct		s_way
{
	t_room			*room;
	struct s_way	*next;
}					t_way;

typedef struct		s_ants
{
	int				name;
	t_way			*way;
	struct s_ants	*next;
}					t_ants;

#endif
