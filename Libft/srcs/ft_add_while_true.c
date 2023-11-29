/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_while_true.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:31:18 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:31:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_add_while_true(int a, char *str, int (*f)(int))
{
	if (!str)
		return (0);
	while (str[a] != '\0' && f(str[a]))
		a++;
	return (a);
}
