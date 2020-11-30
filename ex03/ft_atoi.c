
int	ft_isspace(char c)
{
	return (c == ' ' ||
		c == '\f'||
		c == '\n'||
		c == '\r'||
		c == '\t'||
		c == '\v');
}

int	ft_atoi(char *str)
{
	int sign;
	int nb;

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
	while(*str >='0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}
