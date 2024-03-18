/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:28:42 by skondo            #+#    #+#             */
/*   Updated: 2023/10/16 18:30:09 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

int		ft_printf(const char *format, ...);
char	*ft_changebase_tohexa(unsigned long long n);
int		ft_handle_char(char ch);
int		ft_handle_string(char *str);
int		ft_handle_integer(int i);
int		ft_handle_point(unsigned long long point);
int		ft_handle_unit(unsigned int unit);
int		ft_handle_hexa(unsigned int i, int flag);
int		ft_treat_specifier(char c, va_list args);
int		ft_treat_args(const char *p, va_list args);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_count_output(char *p);
char	*ft_tolower_str(char *c);
char	*ft_toupper_str(char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
