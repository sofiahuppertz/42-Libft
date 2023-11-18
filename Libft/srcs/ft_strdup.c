/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:50:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 14:55:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    char *dup = malloc(ft_strlen(s) + 1);
    if (dup)
        ft_strcpy(dup, s);
    return dup;
}