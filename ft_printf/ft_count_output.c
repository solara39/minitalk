/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:59 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:34:04 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_output(char *p)
{
	int	cnt;

	cnt = 0;
	if (!p)
		return (0);
	cnt = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (cnt);
}
