/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:22:11 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:50:45 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static char	*ft_duplen(const char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c, int *flag)
{
	int		counter;
	char	**stock;
	size_t	i;

	if (!s)
		return (NULL);
	counter = ft_counter(s, c);
	if (counter == 0)
		*flag = 0;
	i = 0;
	stock = (char **) malloc(sizeof(char *) * (counter + 1));
	if (!stock)
		return (NULL);
	counter = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			stock[counter++] = ft_duplen(s + i, c);
		while (s[i] != c && s[i])
			i++;
	}
	stock[counter] = NULL;
	return (stock);
}
