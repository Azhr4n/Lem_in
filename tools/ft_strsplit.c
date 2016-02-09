/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 19:39:53 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 19:39:54 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char		**ft_strsplit(char *str, char c)
{
	char	**tab;
	int		len2;
	int		len;
	int		i;
	int		j;

	len = nb_this_arg(str, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	tab[len] = '\0';
	i = 0;
	while (i < len)
	{
		j = 0;
		len2 = ft_strclen(str, c);
		tab[i] = (char *)malloc(sizeof(char) * (len2 + 1));
		tab[i][len2] = '\0';
		while (j < len2)
			tab[i][j++] = *str++;
		str++;
		i++;
	}
	return (tab);
}
