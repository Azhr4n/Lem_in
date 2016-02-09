/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:41:18 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/03 15:41:22 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0 ;
	while (str[i])
		i++;
	return (i);
}

int			ft_strclen(const char *str, const char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
