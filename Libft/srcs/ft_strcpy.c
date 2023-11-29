/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:37:32 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:37:44 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (save);
}
