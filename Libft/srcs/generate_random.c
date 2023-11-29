/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:33:04 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:33:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

double	generate_random(double min, double max)
{
	double	random;

	random = (double)rand() / RAND_MAX;
	return (min + random * (max - min));
}
