/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:20:04 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:24:49 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;

	cnt = 0;
	if (!format)
		return (0);
	va_start(args, format);
	cnt = ft_treat_args(format, args);
	va_end(args);
	return (cnt);
}
