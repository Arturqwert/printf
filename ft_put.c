#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int len)
{
	int	res;

	res = 0;
	while (*str != '\0' && len > 0)
	{
		res += ft_putchar(*str);
		str++;
		len--;
	}
	return (res);
}

int	ft_putstrlen(char *str, int len)
{
	int		char_count;

	char_count = 0;
	while (str[char_count] && char_count < len)
		ft_putchar(str[char_count++]);
	return (char_count);
}
