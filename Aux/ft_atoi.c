/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:40:11 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 12:40:11 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Verifica se temos um white space ou nao
const char	*ft_white_spaces(const char *nptr)
{
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	return (nptr);
}

//Esta funcao transforma um inteiro de base 10
//numa string com os algarismos do inteiro de base 10
int	ft_atoi(const char *nptr)
{
	int	signal;
	int	nb;

	signal = 1;
	nb = 0;
	nptr = ft_white_spaces(nptr);
	if (*nptr == '-')
	{
		signal *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - '0';
		nptr++;
	}
	return (nb * signal);
}

// int main()
// {
//     printf("mine: %i\n", ft_atoi("2147483650"));
//     printf("their: %i\n", atoi("\e475"));
// }