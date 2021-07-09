#include "ft_printf.h"

int	ft_printf_c(char c, t_treat *treat)
{
	int	res;

	res = 0;
	while (treat->width - 1 > 0)
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

int	ft_printf_d(long nbr, t_treat *treat, t_help *help)
{
	*help = ft_init_help();
	if (nbr < 0)
	{
		help->minus = 1;
		nbr *= -1;
	}
	help->str = ft_itoa(nbr, 10);
	help->len = ft_strlen(help->str);
	if (treat->width > 0)
		treat->width--;
	while (treat->width > help->len)
	{
		help->res += ft_putchar(' ');
		treat->width--;
	}
	if (help->minus == 1)
		help->res += ft_putchar('-');
	help->res += ft_putstr(help->str, ft_strlen(help->str));
	free(help->str);
	return (help->res);
}

// int	ft_printf_d(long nbr, t_treat *treat, t_help *help)
// {
// 	int		res;
// 	char	*str;
// 	int		minus;
// 	int		len;
// 	res = 0;
// 	minus = 0;
// 	if (nbr < 0)
// 	{
// 		minus = 1;
// 		nbr *= -1;
// 	}
// 	str = ft_itoa(nbr, 10);
// 	len = ft_strlen(str);
// 	if (treat->width > 0)
// 		treat->width--;
// 	while (treat->width > len)
// 	{
// 		res += ft_putchar(' ');
// 		treat->width--;
// 	}
// 	if (minus == 1)
// 		res += ft_putchar('-');
// 	while (len > ft_strlen(str))
// 	{
// 		res += ft_putchar('0');
// 		len--;
// 	}
// 	res += ft_putstr(str, ft_strlen(str));
// 	free(str);
// 	return (res);
// }

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
