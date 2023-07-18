#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			c = 'c';
	char			*s = "string";
	int				*p = p;
	int				d = 100;
	int				i = -100;
	unsigned int	u = 100;
	unsigned int	x = 16;
	unsigned int	X = 15;
	char			yüzde = '%';

	printf("\nPRINTF: \n*******************\n");
	printf("char: %c \n", c);
	printf("string: %s \n", s);
	printf("pointer: %p \n", p);
	printf("decimal: %d \n", d);
	printf("integer: %i \n", i);
	printf("unsigned: %u \n", u);
	printf("hex: %x \n", x);
	printf("HEX: %X \n", X);
	printf("%% verince sadece biri yazılıyor\n");//printf("%%: \n", yüzde); bu kısımda printf de hata veriyor

	ft_printf("\nFT_PRINTF: \n*******************\n");
	ft_printf("char: %c \n", c);
	ft_printf("string: %s \n", s);
	ft_printf("pointer: %p \n", p);
	ft_printf("decimal: %d \n", d);
	ft_printf("integer: %i \n", i);
	ft_printf("unsigned: %u \n", u);
	ft_printf("hex: %x \n", x);
	ft_printf("HEX: %X \n", X);
	ft_printf("yüzde: %% \n", yüzde);

	return (0);
}
