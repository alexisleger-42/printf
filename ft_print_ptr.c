/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:20 by aleger            #+#    #+#             */
/*   Updated: 2022/01/26 17:15:59 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_len_ptr(unsigned long long number)
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

void	ft_put_ptr(unsigned long long number)
{
	if (number >= 16)
	{
		ft_put_ptr(number / 16);
		ft_put_ptr(number % 16);
	}
	else
	{
		if (number > 9)
			ft_putchar(number - 10 + 'a');
		else
			ft_putchar(number + '0');
	}
}
