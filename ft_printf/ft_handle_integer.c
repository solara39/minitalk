/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:26:46 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:27:17 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_integer(int i)
{
	char	*str;
	int		cnt;

	str = ft_itoa(i);
	cnt = ft_count_output(str);
	free(str);
	return (cnt);
}
