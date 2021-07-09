#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	// int i = ft_printf("[toto]\n");
	// int a = ft_printf("[%10d]\n", -42);
	// printf("i = %i\n", i);
	// printf("a = %i\n", a);
    void * a;
    a = "42";

    printf("[%10s]\n", "toto");
    ft_printf("[%10s]\n", "toto");
    printf("Magic [%s] is [%10d]\n", "number", -42);
    ft_printf("Magic [%s] is [%10d]\n", "number", -42);
    printf("Hexadecimal x for [%d] is [%10x]\n", -42, 421233516);
    ft_printf("Hexadecimal x for [%d] is [%10x]\n", -42, 421233516);
    printf("Hexadecimal X for [%d] is [%10X]\n", -42, 421233516);
    ft_printf("Hexadecimal X for [%d] is [%10X]\n", -42, 421233516);
    //printf("Pointer for [%d] is [%p]\n", 421233516, 421233516);
    printf("Pointer for [%d] is [%p]\n", 42, a);
    ft_printf("Pointer for [%d] is [%p]\n", 42, a);
    printf("Unsigned for [%d] is [%u]\n", -1, -1);
    ft_printf("Unsigned for [%d] is [%u]\n", -1, -1);
    printf("[%10c]\n", 't');
    ft_printf("[%10c]\n", 't');


    // int	count1;
	// int	count2;
    // count1 = printf("%%\n");
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%%\n");
	// printf("orig count = %d\n\n", count1);

    // count1 = printf("%c + %c = %c\n", '2', '2', '4');
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%c + %c = %c\n", '2', '2', '4');
	// printf("orig count = %d\n\n", count1);

	// count1 = printf("%s + %s = %s\n", "hello", "world", "hello world!");
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%s + %s = %s\n", "hello", "world", "hello world!");
	// printf("orig count = %d\n", count1);
	// count1 = printf("%s + %s = %s\n", "hello", "", "hello  ");
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%s + %s = %s\n", "hello", "", "hello  ");
	// printf("orig count = %d\n\n", count1);


	// count1 = printf("%d + %d = %d\n", -10, 30, 20);
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%d + %d = %d\n", -10, 30, 20);
	// printf("orig count = %d\n\n", count1);

	// count1 = printf("%X + %X = %x\n", -10, 30, 20);
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%X + %X = %x\n", -10, 30, 20);
	// printf("orig count = %d\n\n", count1);


	// count1 = printf("%u + %u = %u\n", -10, 30, 20);
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%u + %u = %u\n", -10, 30, 20);
	// printf("orig count = %d\n\n", count1);

    // int	*p1 = NULL;
	// int *p2 = &count1;

	// count1 = printf("%p + %p\n", p1, p2);
	// printf("orig count = %d\n", count1);
	// count1 = ft_printf("%p + %p\n", p1, p2);
	// printf("orig count = %d\n\n", count1);
}