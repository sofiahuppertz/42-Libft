/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:32:27 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:32:28 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	exit_failure(void)
{
	ft_putstr_fd("Fatal error: Out of memory\n", 2);
	exit(EXIT_FAILURE);
}
