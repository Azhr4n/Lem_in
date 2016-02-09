/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:55:21 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:55:28 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			nb_args(char *str)
{
	int		i;
	int		inc;

	i = 0;
	inc = 1;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\t' || str[i] == ' ')
			{
				while (str[i] && (str[i] == '\t' || str[i] == ' '))
					i++;
				if (str[i])
					inc++;
				else if (inc < 2)
					return (0);
			}
			i++;
		}
	}
	return (inc);
}

int			nb_this_arg(char *str, char c)
{
	int		i;
	int		inc;

	i = 0;
	inc = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			inc++;
		}
		if (str[i])
			i++;
	}
	return (inc);
}
