/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:12:48 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:36:07 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_specifier(char c, va_list args)
{
	int	cnt;

	cnt = 0;
	if (c == 'c')
		cnt = ft_handle_char(va_arg(args, int));
	else if (c == 's')
		cnt = ft_handle_string(va_arg(args, char *));
	else if (c == 'p')
		cnt = ft_handle_point(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		cnt = ft_handle_integer(va_arg(args, int));
	else if (c == 'u')
		cnt = ft_handle_unit(va_arg(args, unsigned int));
	else if (c == 'x')
		cnt = ft_handle_hexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		cnt = ft_handle_hexa(va_arg(args, unsigned int), 2);
	else if (c == '%')
		cnt = ft_count_output("%");
	return (cnt);
}
