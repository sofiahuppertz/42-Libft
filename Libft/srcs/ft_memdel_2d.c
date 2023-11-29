/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:34:00 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:34:02 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_memdel_2d(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		ft_memdel(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return ;
}
