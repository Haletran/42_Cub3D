/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2024/07/28 17:25:54 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	c;
	char	*test;

	c = 0;
	if (elementCount <= 0 || elementSize <= 0)
		return (malloc(1));
	if ((long)elementSize < 0 || (long)elementCount < 0)
		return (NULL);
	test = malloc(elementSize * elementCount);
	if (!test)
		return (NULL);
	while (c < elementSize * elementCount)
		test[c++] = 0;
	return (test);
}
