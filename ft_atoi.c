/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:40:32 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 21:19:38 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, int *flag)
{
	int		i;
	long	res;
	int		sign;

	(1) && (i = 0, res = 0, sign = 1);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] == '\0')
		return (*flag = 0, -1);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (*flag = 0, -1);
		res = res * 10 + (nptr[i++] - 48);
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && res * sign < INT_MIN))
			return (*flag = 0, -1);
	}
	return (res * sign);
}
