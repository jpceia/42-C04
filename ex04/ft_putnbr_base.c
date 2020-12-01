/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:33:22 by jceia             #+#    #+#             */
/*   Updated: 2020/12/01 19:26:48 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_base_size(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		signal;
	char	digits[32];
	int		base_size;
	int		index;

	base_size = ft_base_size(base);
	if (base_size < 2)
		return ;
	signal = nb > 0 ? 1 : -1;
	if (nb < 0)
		write(1, "-", 1);
	else if (nb == 0)
	{
		write(1, base, 1);
		return ;
	}
	index = 0;
	while (nb != 0)
	{
		digits[index++] = (char)(signal * (nb % base_size));
		nb /= base_size;
	}
	while (index > 0)
		write(1, &base[(int)digits[--index]], 1);
}
