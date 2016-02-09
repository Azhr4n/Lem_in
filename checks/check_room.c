/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:48:15 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:48:18 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "checks.h"
#include "tools.h"

static int	check_room2(char *str)
{
	int		i;

	i = 0;
	while(str[i] != ' ' && str[i] != '\t')
		i++;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	while(str[i] <= '9' && str[i] >= '0')
		i++;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	while(str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

int			check_room(char *str)
{
	int		i;
	int		nb_a;
	char	*tmp;

	if (!str)
		return (0);
	tmp = del_space(str);
	nb_a = nb_args(tmp);
	if (nb_a != 3 || tmp[0] == '#')
	{
		free(tmp);
		return (0);
	}
	else
		i = check_room2(tmp);
	if (!tmp[i])
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
