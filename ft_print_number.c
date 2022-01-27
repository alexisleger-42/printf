/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:37 by aleger            #+#    #+#             */
/*   Updated: 2022/01/27 11:42:20 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	i = ft_len(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

int	ft_print_number(int number)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(number);
	i += ft_print_str(str);
	free(str);
	return (i);
}
