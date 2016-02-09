/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:49:45 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:49:46 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "checks.h"
#include "tools.h"

static int	check_pipe_next(t_room *room, char *name, char *str, int len)
{
	t_room	*start;

	start = room;
	while (start)
	{
		if (ft_strcmp(name, start->name))
		{
			free(name);
			start = room;
			while (start)
			{
				if (ft_strcmp((str + len + 1), start->name))
				{
					free(str);
					return (1);
				}
				start = start->next;
			}
			free(str);
			return (0);
		}
		start = start->next;
	}
	free(str);
	free(name);
	return (0);
}

int			check_pipe(char *str, t_room *room)
{
	char	*name;
	char	*tmp;
	int		len;

	tmp = del_space(str);
	len = ft_strclen(tmp, '-');
	if (len == -1)
		return (0);
	name = ft_strcdup(tmp, '-');
	if (ft_strcmp(name, tmp + len + 1))
	{
		free(tmp);
		free(name);
		return (0);
	}
	return (check_pipe_next(room, name, tmp, len));
}
