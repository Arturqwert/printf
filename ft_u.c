#include "ft_printf.h"

int	ft_put_uint(char *unsi_int, t_treat *treat)
{
	int		char_count;

	char_count = 0;
	char_count += ft_width_treat(treat->width, ft_strlen(unsi_int), 0);
	char_count += ft_putstrlen(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

int	ft_printf_u(unsigned int unsi, t_treat *treat)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1 + unsi);
	unsi_int = ft_u_itoa(unsi);
	char_count += ft_put_uint(unsi_int, treat);
	free(unsi_int);
	return (char_count);
}
