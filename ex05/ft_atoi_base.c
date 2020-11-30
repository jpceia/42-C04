
int	ft_isspace(char c)
{
	return (c == ' ' ||
		c == '\f'||
		c == '\n'||
		c == '\r'||
		c == '\t'||
		c == '\v');
}

int	ft_chartoi(char c, char *base)
{
	int i;
	while (base[i] != 0)
	{
		if(c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base)
{
	int i;
	int base_size;
	int sign;
	int nb;

	base_size = ft_strlen(base);
	while(ft_isspace(*str))
		str++;
	sign = 1;
	while(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign *= -1;
		str++;
	}
	nb = 0;
	while (1)
	{
		i = ft_chartoi(*str);
		if (i < 0)
			break;
		nb = nb * base_size + i;
		str++;
	}
	return (sign * nb);
}
