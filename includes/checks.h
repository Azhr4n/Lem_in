/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:45:55 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:45:56 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "struct.h"

int			check_command(char *str);
int			check_pipe(char *str, t_room *room);
int			check_param_ants(char *str);
int			check_room(char *str);

#endif
