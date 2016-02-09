/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:38:56 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:38:57 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "checks.h"
#include "tools.h"

static int	check_param_ants2(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i])
			{
				if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
				{
					free(str);
					return (0);
				}
				i++;
			}
		}
		else if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		{
			free(str);
			return (0);
		}
		if (str[i])
			i++;
	}
	free(str);
	return (1);
}

int			check_param_ants(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = del_space(str);
	return (check_param_ants2(tmp, 0));
}
