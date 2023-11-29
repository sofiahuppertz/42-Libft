/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:35:15 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:35:21 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_is_all(const char *str, int (*f)(int))
{
	while (*str)
	{
		if (!f(*str))
			return (0);
		str++;
	}
	return (1);
}
