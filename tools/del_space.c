/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:54:31 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:54:31 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

static void	limit_str(char *str, int tab[2])
{
	int		i;
	int		len;

	if (nb_args(str) > 0)
	{
		i = 0;
		len = ft_strlen(str);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		tab[0] = i;
		i = len - tab[0];
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		tab[1] = i;
	}
}

char		*del_space(char *str)
{
	int		tab[2] = {0, 0};
	char	*n_str;
	int		len;
	int		i;

	i = 0;
	limit_str(str, tab);
	len = tab[1] - tab[0] + 1;
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	ft_zfill(n_str, len + 1);
	while (tab[0] + i <= tab[1])
	{
		n_str[i] = str[tab[0] + i];
		i++;
	}
	return (n_str);
}
