/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:54:39 by aleger            #+#    #+#             */
/*   Updated: 2022/01/27 10:56:17 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_char(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_print_percent(int c)
{
	c = '%';
	ft_putchar(c);
	return (1);
}

int	ft_print_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_print_percent(va_arg(args, int));
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += ft_print_format(args, format[i + 1]);
			i++;
		}
		else
			print_len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
