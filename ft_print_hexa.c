/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:47 by aleger            #+#    #+#             */
/*   Updated: 2022/01/26 17:16:07 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hexa(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_put_hexa(number / 16, format);
		ft_put_hexa(number % 16, format);
	}
	else
	{
		if (number > 9)
		{
			if (format == 'x')
				ft_putchar(number - 10 + 'a');
			if (format == 'X')
				ft_putchar(number - 10 + 'A');
		}
		else
			ft_putchar(number + '0');
	}
}

int	ft_len_hexa(unsigned int number)
{
	int	i;

	i = 0;
	while (i)
	{
		number = number / 16;
		i++;
	}
	return (i);
}
