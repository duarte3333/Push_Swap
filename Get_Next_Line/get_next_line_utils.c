/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:27 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/29 18:20:27 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

//Se a string for NULL retorna 0
//Se a string for vazia retorna 0
//Se a string nao tiver \n retorna o seu size
//Se a string tive \n retorna o seu size + 1
static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

//Esta funcao recebe duas strings e faz a concatenação de ambas
//ou seja, junta-as
//Enquanto a line existir e a line for diferente de '\0' -> juntar
//Enquanto o buffer for diferente de '\0' -> juntar
//O buffer vai exitir sempre
//Se chegarmos a uma \n damos break pois acabou a line
char	*ft_strjoin(char *s1, char *s2)
{
	int		size_concat;
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = -1;
	size_concat = ft_strlen(s1) + ft_strlen(s2);
	concat = (char *)malloc(size_concat + 1 * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1 && s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		concat[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	concat[i] = 0;
	free(s1);
	return (concat);
}
