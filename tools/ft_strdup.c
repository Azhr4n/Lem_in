/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:52:18 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:52:19 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char	*ft_strcdup(const char *str, const char c)
{
	char	*n_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strclen(str, c);
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	ft_zfill(n_str, len + 1);
	while (str[i] != c && str[i])
	{
		n_str[i] = str[i];
		i++;
	}
	return (n_str);
}
