/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:15:41 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/07/18 10:18:53 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n, char *base)
/*verilen uintptr_t tipindeki sayıyı verilen base'e göre yazdırır ve yazdırdığı karakter sayısını döndürür yazdıramazsa -1 döndürür*/
{
	size_t count;
	size_t base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= (uintptr_t)base_len)
	{
		count += ft_putptr(n / base_len, base);
		count += ft_putptr(n % base_len, base);
	}
	else
		count += ft_putchar(base[n % base_len]);
	return (count);
}

int	ft_unsnd_putnbr_base(unsigned int nbr, char *base)
// sadece işaretsiz değer alabilir
/* sayıyı verilen base'e göre yazdırır ve yazdırdığı karakter sayısını döndürür yazdıramazsa -1 döndürür*/
{
	size_t count;
	size_t base_len;
	int tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned int)base_len)
	{
		tmp = ft_unsnd_putnbr_base(nbr / base_len, base);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(base[nbr % base_len]) == -1)
		return (-1);
	return (++count);
}

int	ft_putnbr(int nb) // standart putnbr fonksiyonu
{
	size_t count;
	long number;
	int tmp;

	count = 0;
	number = nb;
	if (nb < 0)
	{
		number *= -1;
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
	}
	if (number >= 10)
	{
		tmp = ft_putnbr(number / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(number % 10 + '0') == -1)
		return (-1);
	return (++count);
}

size_t	ft_strlen(const char *str) // stringin uzunluğunu döndürür
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}
