#include "ft_printf.h"

t_treat	init(void)
{
	t_treat	treat;

	treat.width = 0;
	return (treat);
}

// int ft_printf(const char *str, ... )
// {
// 	t_treat treat;
//     int i = 0;
// 	int res = 0;
//     va_list ap;

//     va_start(ap, str);
//     while (str[i] != '\0')
//     {
//         if (str[i] == '%' && str[i+1] != '\0')
//         {
//             i++;
// 			treat = init();
//             while (str[i] >= '0' && str[i] <= '9')
//             {
//                 treat.width = treat.width * 10 + (str[i] - '0');
//                 i++;
//             }
//             if (str[i] == 's')
//                 res += ft_printf_s(va_arg(ap, char *), &treat);
//             else if (str[i] == 'c')
//                 res += ft_printf_c(va_arg(ap, int), &treat);
//             else if (str[i] == 'x' || str[i] == 'X')
//                 res += ft_printf_x(va_arg(ap, unsigned int), &treat, str[i]);
//             else if (str[i] == 'd' || str[i] == 'i')
//                 res += ft_printf_d(va_arg(ap, int), &treat);
//             else if (str[i] == 'p')
//                 res += ft_printf_p(va_arg(ap, unsigned long long), &treat);
//             else if (str[i] == 'u')
//                 res += ft_printf_u(va_arg(ap, unsigned int), &treat);
//             else if (str[i] == '%')
//                 res += ft_printf_percent(&treat);
//             else
//                 res += ft_putchar(str[i]);
//         }
//         else
//             res += ft_putchar(str[i]);
//         i++;
//     }
//     va_end(ap);
//     return (res);
// }

int	ft_parse(int c, t_treat treat, va_list ap, t_help *help)
{
	int	res;

	res = 0;
	if (c == 's')
		res += ft_printf_s(va_arg(ap, char *), &treat);
	else if (c == 'c')
		res += ft_printf_c(va_arg(ap, int), &treat);
	else if (c == 'x' || c == 'X')
		res += ft_printf_x(va_arg(ap, unsigned int), &treat, c);
	else if (c == 'd' || c == 'i')
		res += ft_printf_d(va_arg(ap, int), &treat, help);
	else if (c == 'p')
		res += ft_printf_p(va_arg(ap, unsigned long long), &treat);
	else if (c == 'u')
		res += ft_printf_u(va_arg(ap, unsigned int), &treat);
	else if (c == '%')
		res += ft_printf_percent(&treat);
	else
		res += ft_putchar(c);
	return (res);
}

int	ft_treat(const char *str, va_list args)
{
	t_treat	treat;
	t_help	help;
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			treat = init();
			while (str[i] >= '0' && str[i] <= '9')
			{
				treat.width = treat.width * 10 + (str[i] - '0');
				i++;
			}
			ft_parse(str[i], treat, args, &help);
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			res;
	const char	*cpy;

	cpy = ft_strdup((char *)str);
	res = 0;
	va_start(args, str);
	res += ft_treat(cpy, args);
	va_end(args);
	free((char *)cpy);
	return (res);
}
