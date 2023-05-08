/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:38:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/08 11:57:58 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	int				result;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s[i] != d[i])
		{
			result = (unsigned char *)&s[i] - (unsigned char *)&d[i];
			return (result);
		}
		i++;
	}
	return (0);
}
