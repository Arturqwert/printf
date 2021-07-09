#include "ft_printf.h"

char	*ft_itoa(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	temp_nbr = nbr;
	len = 0;
	str = NULL;
	if (nbr == 0)
		len++;
	while (temp_nbr > 0 && len++ >= 0)
		temp_nbr /= base;
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}

char	*ft_Xitoa(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	temp_nbr = nbr;
	len = 0;
	str = NULL;
	if (nbr == 0)
		len++;
	while (temp_nbr > 0 && len++ >= 0)
		temp_nbr /= base;
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'A' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}

char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*res;
	long	nbr;
	int		isneg;

	isneg = 0;
	nbr = n;
	len = ft_estim(nbr);
	res = 0;
	res = ft_generate(res, nbr, len, isneg);
	if (!res)
		return (0);
	return (res);
}

int	ft_estim(long n)
{
	size_t	estim;

	estim = 0;
	if (n < 0)
	{
		estim++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

char	*ft_generate(char *res, long nbr, int len, int isneg)
{
	if (nbr != 0)
		res = malloc(sizeof(char) * (len + 1));
	else
	{
		res = ft_strdup("0");
		return (res);
	}
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	res[len] = '\0';
	while (--len)
	{
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		res[0] = '-';
	else
		res[0] = (nbr % 10) + '0';
	return (res);
}
