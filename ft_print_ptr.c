/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:20 by aleger            #+#    #+#             */
/*   Updated: 2022/02/03 12:07:10 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long long number)
{
	int	i;

	i = 0;
	while (number)
	{
		number = number / 16;
		i++;
	}
	return (i);
}

void	ft_put_ptr(unsigned long long number)
{
	if (number >= 16)
	{
		ft_put_ptr(number / 16);
		ft_put_ptr(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar(number + '0');
		else
			ft_putchar(number - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		i = ft_len_ptr(ptr);
	}
	return (i);
}
