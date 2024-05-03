/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:57:01 by baptiste          #+#    #+#             */
/*   Updated: 2023/11/27 09:49:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_special(unsigned int n, unsigned int fd);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_putnbr_base_ptr(unsigned long long nb, char *base);
int	v_pointer(unsigned long long ptr, char *base);
int	check_del(char format);
int	check_identifier(int len, char format, va_list args);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);

#endif
