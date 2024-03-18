/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:07:41 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:26:07 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_point(unsigned long long point)
{
	char	*p;
	int		cnt;

	p = ft_changebase_tohexa(point);
	cnt = ft_count_output("0x");
	cnt += ft_count_output(p);
	free(p);
	return (cnt);
}
