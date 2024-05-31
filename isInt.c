
int	ft_isnbr(char *s)
{
	if (ft_issign(*s) && ft_isdigit(*(s + 1)))
		++s;
	while (ft_isdigit(*s))
		++s;
	if (!ft_isempty(s))
		return (0);
	return (1);
}

char	*ft_get_non_zero_digit(char *s)
{
	if (ft_issign(*s))
		++s;
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_is_str_int(char *s)
{
	char	sign;
	int		len;

	if (!ft_isnbr(s))
		return (0);
	sign = *s;
	s = ft_get_non_zero_digit(s);
	len = ft_strlen(s);
	if (len != 10)
		return (len < 10);
	if (sign == '-')
		return (ft_strncmp(STR_MIN_INT, s, len) >= 0);
	return (ft_strncmp(STR_MAX_INT, s, len) >= 0);
}