#include "ft_printf.h"

int	ft_printf_c(char c, t_treat *treat)
{
	int	res;

	res = 0;
	while (treat->width -1 > 0)
	{
		res = ft_putchar(' ');
		treat->width--;
	}
	ft_putchar(c);
	return (res + 1);
}

int	ft_printf_s(char *str, t_treat *treat)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(str);
	while (treat->width > len)
	{
		res += ft_putchar(' ');
		treat->width--;
	}
	ft_putstr(str, len);
	return (res);
}

typedef struct s_help
{
	int		res;
	char	*str;
	int		minus;
	int		len;
}				t_help;

t_help	ft_init_help(void)
{
	t_help	help;

	help.res = 0;
	help.minus = 0;
	return (help);
}

int	ft_printf_d(long nbr, t_treat *treat)
{
	// int		res;
	// char	*str;
	// int		minus;
	// int		len;
	t_help	help;
	// res = 0;
	// minus = 0;
	help = ft_init_help();
	//ft_help(&str, &len, nbr, *treat);
	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if (treat->width > 0)
		treat->width--;
	while (treat->width > len)
	{
		res += ft_putchar(' ');
		treat->width--;
	}
	if (minus == 1)
		res += ft_putchar('-');
	while (len > ft_strlen(str))
	{
		res += ft_putchar('0');
		len--;
	}
	res += ft_putstr(str, ft_strlen(str));
	free(str);
	return (res);
}

int	ft_help(int *res, char **str, int *minus, int *len, int nbr, t_treat treat)
{
	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if (treat->width > 0)
		treat->width--;
	while (treat->width > len)
	{
		res += ft_putchar(' ');
		treat->width--;
	}
	if (minus == 1)
		res += ft_putchar('-');
	while (len > ft_strlen(str))
	{
		res += ft_putchar('0');
		len--;
	}
	res += ft_putstr(str, ft_strlen(str));
	free(str);
	return (res);
}

int	ft_printf_x(unsigned long nbr, t_treat *treat, char c)
{
	char	*str;
	int		len;
	int		res;

	if (c == 'x')
		str = ft_itoa(nbr, 16);
	else if (c == 'X')
		str = ft_Xitoa(nbr, 16);
	len = ft_strlen(str);
	res = 0;
	while (treat->width > len)
	{
		res += ft_putchar(' ');
		treat->width--;
	}
	while (len > ft_strlen(str))
	{
		res += ft_putchar('0');
		len--;
	}
	res += ft_putstr(str, ft_strlen(str));
	free(str);
	return (res);
}

int	ft_printf_percent(t_treat *treat)
{
	int	res;

	res = 0;
	res += ft_width_treat(treat->width, 1, 0);
	res += ft_putstrlen("%", 1);
	return (res);
}
