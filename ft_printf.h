/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:33:34 by aleger            #+#    #+#             */
/*   Updated: 2022/01/29 14:50:02 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		ft_len(long n);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_len_ptr(unsigned long long number);
void	ft_put_ptr(unsigned long long number);
int		ft_len_hexa(unsigned int number);
void	ft_put_hexa(unsigned int number, const char format);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_number(int number);
int		ft_print_unsigned(unsigned int number);
int		ft_print_hexa(unsigned int number, const char format);
int		ft_printpercent(void);
int		ft_print_format(va_list args, const char format);
int		ft_printf(const char *format, ...);

#endif
