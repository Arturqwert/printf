#include "ft_printf.h"

char	*base_treat(unsigned long long ull_save, int base, char *res,
int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			res[count - 1] = (ull_save % base) + 48;
		else
			res[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (res);
}

char	*ft_ull_base(unsigned long long ull, int base)
{
	char				*res;
	unsigned long long	ull_save;
	int					count;

	res = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	res = malloc(sizeof(char) * (count + 1));
	if (!res)
		return (0);
	res[count] = '\0';
	res = base_treat(ull_save, base, res, count);
	return (res);
}

int	ft_width_treat(int width, int minus, int has_zero)
{
	int		char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		char_count++;
	}
	return (char_count);
}

int	ft_put_pointer(char *pointer)
{
	int	char_count;

	char_count = 0;
	char_count += ft_putstrlen("0x", 2);
	char_count += ft_putstrlen(pointer, ft_strlen(pointer));
	return (char_count);
}

int	ft_printf_p(unsigned long long ull, t_treat *treat)
{
	char	*p;
	int		res;

	res = 0;
	p = ft_ull_base(ull, 16);
	p = ft_str_tolower(p);
	res += ft_width_treat(treat->width, ft_strlen(p) + 2, 0);
	res += ft_put_pointer(p);
	free(p);
	return (res);
}
