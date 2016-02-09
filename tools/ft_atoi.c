/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:01:32 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/03 16:01:33 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			ft_atoi(const char *str)
{
	int		ret;
	int		len;
	int		tmp;
	int		inc;
	int		i;

	len = ft_strlen(str);
	i = 0;
	ret = 0;
	while (i < len)
	{
		tmp = len - (i + 1);
		inc = 1;
		while (tmp)
		{
			inc *= 10;
			tmp--;
		}
		ret += (str[i] - '0') * inc;
		i++;
	}
	return (ret);
}
