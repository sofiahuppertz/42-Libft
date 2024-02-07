/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:35:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 13:01:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_is_all(const char *str, int (*f)(int))
{
	if (str == NULL)
		return (1);
	while (*str)
	{
		if (!f(*str))
			return (0);
		str++;
	}
	return (1);
}
