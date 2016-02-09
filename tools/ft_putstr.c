/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:36:31 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/05 14:36:31 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "tools.h"

void		ft_putstr(const char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
}

void		ft_putendl(const char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
