/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/05 13:05:34 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void			*ptr;
	int				total_size;
	int				i;
	unsigned char	*byte_ptr;

	if ((elements > 0 && SIZE_MAX / elements < size) || elements <= 0
		|| size <= 0)
	{
		return (NULL);
	}
	total_size = size * elements;
	ptr = malloc(total_size);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	if (ptr != NULL)
	{
		while (i < total_size)
		{
			byte_ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
