/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:27:40 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:27:41 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hexa(unsigned int i, int flag)
{
	char	*p;
	int		cnt;

	cnt = 0;
	if (i == 0)
		cnt += write(1, "0", 1);
	else
	{
		p = ft_changebase_tohexa(i);
		if (p == NULL)
			return (0);
		if (flag == 1)
			ft_tolower_str(p);
		else
			ft_toupper_str(p);
		cnt = ft_count_output(p);
		free(p);
	}
	return (cnt);
}
