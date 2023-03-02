/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:33:47 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:33:47 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

char	**recursive_split(char *str, char **arr, int words, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = 0;
	while (str && *str && *str == c)
		str++;
	while (str && str[i] && str[i] != c)
		i++;
	if (i > 0)
		new_str = (char *)malloc(i + 1);
	if (new_str)
		new_str[i] = 0;
	i = 0;
	while (new_str && str && *str && *str != c)
		new_str[i++] = *str++;
	if (new_str)
		arr = recursive_split(str, arr, words + 1, c);
	else
		arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr)
		arr[words] = new_str;
	return (arr);
}

char	**ft_split(const char *str, char c)
{
	return (recursive_split((char *)str, NULL, 0, c));
}
