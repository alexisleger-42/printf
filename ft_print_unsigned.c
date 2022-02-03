/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:41 by aleger            #+#    #+#             */
/*   Updated: 2022/01/29 14:44:01 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_itoa(unsigned int n)
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
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int number)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (number == 0)
		i += write(1, "0", 1);
	else
	{
		str = ft_unsigned_itoa(number);
		i = ft_print_str(str);
		free(str);
	}
	return (i);
}
