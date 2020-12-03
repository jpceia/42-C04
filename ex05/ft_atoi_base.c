/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:12:41 by jceia             #+#    #+#             */
/*   Updated: 2020/12/03 20:59:08 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	return (c == ' '
			|| c == '\f'
			|| c == '\n'
			|| c == '\r'
			|| c == '\t'
			|| c == '\v');
}

int		ft_chartoi_base(char c, char *base)
{
	int index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int		ft_base_size(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
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

int		ft_atoi_base(char *str, char *base)
{
	int index;
	int base_size;
	int sign;
	int nb;

	base_size = ft_base_size(base);
	if (base_size < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
		sign = *(str++) == '-' ? -sign : sign;
	nb = 0;
	while (*str)
	{
		index = ft_chartoi_base(*str, base);
		if (index < 0)
			break ;
		nb = nb * base_size + index;
		str++;
	}
	return (sign * nb);
}
