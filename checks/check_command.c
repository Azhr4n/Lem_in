/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:50:57 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:50:58 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "checks.h"
#include "tools.h"

int			check_command(char *str)
{
	char	*tmp;

	tmp = del_space(str);
	if (ft_strcmp("##Start", tmp) || ft_strcmp("##start", tmp))
	{
		free(tmp);
		return (1);
	}
	else if (ft_strcmp("##End", tmp) || ft_strcmp("##end", tmp))
	{
		free(tmp);
		return (2);
	}
	free(tmp);
	return (0);
}
