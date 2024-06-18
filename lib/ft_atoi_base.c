/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:56:28 by baptiste          #+#    #+#             */
/*   Updated: 2024/06/18 22:56:44 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi_base(const char *str, const char *base)
{
    int i;
    int j;
    int sign;
    int res;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i])
    {
        j = 0;
        while (base[j] && str[i] != base[j])
            j++;
        if (!base[j])
            return (res * sign);
        res = res * ft_strlen(base) + j;
        i++;
    }
    return (res * sign);
}