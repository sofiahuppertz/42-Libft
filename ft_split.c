/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:43:45 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 18:01:54 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_substrings(char const *s, char c)
{
	int	i;
	int	len;
	int	count;

	len = ft_strlen(s);
	count = 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

void	extract_substrings(const char *s, char c, char **result)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		k = j;
		i++;
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;

	count = count_substrings(s, c);
	result = (char **)malloc(count + 1 * sizeof(char *));
	if (!result)
		return (NULL);
	extract_substrings(s, c, result);
	if (result)
		result[count] = NULL;
	return (result);
}int		count;
	char	**result;

	count = count_substrings(s, c);
	result = (char **)malloc(count + 1 * sizeof(char *));
	if (!result)
		return (NULL);
	extract_substrings(s, c, result);
	if (result)
		result[count] = NULL;
	return (result);
}
