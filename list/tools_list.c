/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:38:16 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/12 18:38:17 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			nb_room(t_room *room)
{
	t_room	*start;
	int		i;

	i = 0;
	start = room;
	while (start)
	{
		start->nb = i;
		start = start->next;
		i++;
	}
	return (i);
}
