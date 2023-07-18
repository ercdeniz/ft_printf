/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utilities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:13:42 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/07/18 10:19:45 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)//karakteri yazdırır ve yazdırdığı karakter sayısını döndürür (1) yazdıramazsa -1 döndürür
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)//stringi yazdırır ve yazdırdığı karakter sayısını döndürür yazdıramazsa -1 döndürür
{
	size_t	count;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	count = 0;
	while (*str)
	{
		if (ft_putchar(*str++) == -1)
			return (-1);
		count++;
	}
	return (count);
}
