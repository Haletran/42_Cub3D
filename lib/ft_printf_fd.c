/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:55:08 by bapasqui          #+#    #+#             */
/*   Updated: 2024/05/21 18:39:53 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		len;
	int		i;
	va_list	pointer;

	len = 0;
	i = 0;
	va_start(pointer, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr_fd(va_arg(pointer, char *), fd);
			else if (format[i] == 'd')
				len += ft_putnbr_fd(va_arg(pointer, int), fd);
			else if (format[i] == 'c')
				len += ft_putchar_fd(va_arg(pointer, int), 1);
		}
		else
			len += write(fd, &format[i], 1);
		i++;
	}
	va_end(pointer);
	return (len);
}
