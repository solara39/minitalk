/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:21:23 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:21:40 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tolower_str(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_tolower(c[i]);
		i++;
	}
	return (c);
}
