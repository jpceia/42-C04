/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:33:22 by jceia             #+#    #+#             */
/*   Updated: 2020/12/01 16:46:13 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit_n(int x, int n)
{
	char c;

	while (n > 0)
	{
		x /= 10;
		n--;
	}
	x = x % 10;
	c = '0' + x;
	write(1, &c, 1);
}

int		get_nr_figures(int x)
{
	int n_figures;

	x = x < 0 ? -x : x;
	n_figures = 0;
	while (x > 0)
	{
		x /= 10;
		n_figures++;
	}
	return (n_figures);
}

void	ft_putnbr(int nb)
{
	int i;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 12);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		i = get_nr_figures(nb) - 1;
		while (i >= 0)
		{
			print_digit_n(nb, i);
			i--;
		}
	}
}
