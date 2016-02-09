/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:16:38 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/03 16:16:39 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if ((n / 10) != 0)
	{
		if (n < 0)
			ft_putnbr(-(n / 10));
		else
			ft_putnbr(n / 10);
	}
	n %= 10;
	if (n < 0)
		n = -n;
	ft_putchar(n + '0');
}

void		ft_putnbr2(int n)
{
	if (n < 0)
		ft_putchar('-');
	if ((n / 10) != 0)
	{
		if (n < 0)
			ft_putnbr(-(n / 10));
		else
			ft_putnbr(n / 10);
	}
	n %= 10;
	if (n < 0)
		n = -n;
	ft_putchar(n + '0');
	ft_putchar('\n');
}
