/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:57:41 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/07/17 13:34:23 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;

	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			tmp = format_selector(format[i + 1], args);
			if (tmp == -1)
				return (-1);
			count += (tmp - 1);
			i++;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		count++;
	}
	va_end(args);
	return (count);
}

int	format_selector(char format, va_list args)
{
	int	tmp;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		tmp = ft_putptr(va_arg(args, uintptr_t), BASE16LOWER);
		if (tmp == -1)
			return (-1);
		return (tmp + 2);
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
		return (ft_putchar('%'));
}
