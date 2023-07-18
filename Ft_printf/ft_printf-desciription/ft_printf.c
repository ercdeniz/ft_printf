/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:08:49 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/07/17 20:08:50 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)//standart printf fonksiyonunun taklidi
//başlamadan önce 'stdarg.h' kütüphanesi ve 'va_' fonksiyonlarını inceleyin
{
	va_list	args;//değişken argümanlar listesi oluşturuyoruz
	int		count;//yazdırılan karakter sayısını tutacak değişken
	int		i;//döngü sayacı
	int		tmp;//format_selector fonksiyonundan dönen değeri tutacak değişken

	va_start(args, format);//args listesini format ile başlatıyoruz
	count = 0;
	i = -1;//döngü içinde arttırarak başladığı için -1
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		//% karakteri gördüğünde format_selector ile hangi format olduğunu buluyoruz
		{
			tmp = format_selector(format[i + 1], args);//% den sonraki karakteri alıyoruz formatı buluyoruz
			if (tmp == -1)
				return (-1);
			count += (tmp - 1);
			i++;
		}
		else if (ft_putchar(format[i]) == -1)//% olmayan karakterleri yazdırıyoruz
			return (-1);
		count++;
	}
	va_end(args);//args listesini bitiriyoruz
	return (count);//yazdırılan karakter sayısını döndürüyoruz
}

/*
NOT: Kod içerisinde yapılan -1 kontrolleri write fonksiyonunun dönüş değerini kontrol etmek içindir.
Write eğer -1 döndürürse ft_printf de -1 döndermelidir.
Bundan dolayı bu kontrol her putchar kullanılan yerlerde veya putcharı kullanan başka fonksiyonun kullanıldığı yerde yapılmalı
*/

int	format_selector(char format, va_list args)//formatı belirler ve ilgili fonksiyonu çağırır
{
	int	tmp;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		if (ft_putstr("0x") == -1)//bellek adresi olduğunu belirtmek için 0x ekliyoruz
			return (-1);
		tmp = ft_putptr(va_arg(args, uintptr_t), BASE16LOWER);
		if (tmp == -1)
			return (-1);
		return (tmp + 2);//0x eklediğimiz için +2 yapıyoruz
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE10));
	else if (format == 'x')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE16LOWER));
	else if (format == 'X')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE16UPPER));
	else
		return (ft_putchar('%'));//ard arda iki tane % olursa % karakterini yazdırıyoruz
}
