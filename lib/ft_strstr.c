/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:31:43 by bapasqui          #+#    #+#             */
/*   Updated: 2024/08/12 19:29:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	if (to_find[0] == '\0' || to_find == 0)
		return (str);
	if (str == 0)
		return (0);
	while (str[c] != '\0')
	{
		while (str[c + d] == to_find[d])
		{
			d++;
			if (to_find[d] == '\0')
				return (&str[c]);
		}
		d = 0;
		c++;
	}
	return (0);
}
