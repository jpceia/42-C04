/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:12:41 by jceia             #+#    #+#             */
/*   Updated: 2020/12/01 18:58:54 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' '
			|| c == '\f'
			|| c == '\n'
			|| c == '\r'
			|| c == '\t'
			|| c == '\v');
}

int	ft_chartoi_base(char c, char *base)
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

int	ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int index;
	int base_size;
	int sign;
	int nb;

	base_size = ft_strlen(base);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
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
