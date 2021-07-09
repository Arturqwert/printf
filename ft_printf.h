#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//delete//
# include <stdio.h>
//delete//
typedef struct s_treat
{
	va_list	args;
	int		width;
}			t_treat;

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str, int len);
int		ft_strlen(char *str);
char	*ft_itoa(unsigned long nbr, int base);
char	*ft_Xitoa(unsigned long nbr, int base);
char	*ft_u_itoa(unsigned int n);

int		ft_printf_x(unsigned long nbr, t_treat *treat, char c);
int		ft_printf_d(long nbr, t_treat *treat);
int		ft_printf_s(char *str, t_treat *treat);
int		ft_printf_c(char c, t_treat *treat);
int		ft_printf_p(unsigned long long ull, t_treat *treat);
int		ft_printf_u(unsigned int unsi, t_treat *treat);
int		ft_printf_percent(t_treat *treat);

t_treat	init(void);

char	*ft_strdup(char *s1);
char	*base_treat(unsigned long long ull_save, int base, char *res,
			int count);
char	*ft_ull_base(unsigned long long ull, int base);
int		ft_tolower(int c);
char	*ft_str_tolower(char *str);
int		ft_width_treat(int width, int minus, int has_zero);
int		ft_putstrlen(char *str, int len);
int		ft_put_pointer(char *pointer);
int		ft_estim(long n);
char	*ft_generate(char *res, long nbr, int len, int isneg);
int		ft_put_uint(char *unsi_int, t_treat *treat);

int		ft_treat(const char *str, va_list args);
int		ft_parse(int c, t_treat treat, va_list ap);

#endif