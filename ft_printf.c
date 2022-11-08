/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:40:57 by gmarchal          #+#    #+#             */
/*   Updated: 2022/11/08 16:27:46 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	i = 0;
	count = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (!str)
			return (0);
		else if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				count += ft_putchar(va_arg(arguments, int));
			else if (str[i] == 's')
				count += ft_putstr(va_arg(arguments, char *));
			else if (str[i] == 'p')
			{
				write(1, "0x", 2);
				count += 2 + ft_putptr(va_arg(arguments, unsigned long));
			}
			else if (str[i] == 'd')
				count += ft_putnbr(va_arg(arguments, int));
			else if (str[i] == 'i')
				count += ft_putnbr(va_arg(arguments, int));
			else if (str[i] == 'u')
				count += ft_putunsigned(va_arg(arguments, unsigned int));
			else if (str[i] == 'x')
				count += ft_puthexlow(va_arg(arguments, unsigned int));
			else if (str[i] == 'X')
				count += ft_puthexup(va_arg(arguments, unsigned int));
			else if (str[i] == '%')
				count += ft_putchar('%');
		}
		else
		{
			count++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arguments);
	return (count);
}
