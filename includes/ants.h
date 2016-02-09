/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 23:25:27 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 23:25:28 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTS_H
# define ANTS_H

# include "struct.h"

void		moving_ants(t_world *world, t_ants *ants, t_way *way);
t_ants		*new_ants(t_ants *ants, t_way *way, int nb);
t_ants		*chain_ants(t_world *world, t_way *way);
void		print_ant(t_ants *ants);

#endif
