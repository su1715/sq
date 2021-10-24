/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:48:50 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 19:59:30 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_min(int left, int up, int left_up)
{
	int	min;

	min = 2147483647;
	if (left < min)
		min = left;
	if (up < min)
		min = up;
	if (left_up < min)
		min = left_up;
	return (min);
}

int	is_overlap(char empty, char obs, char fill)
{
	if (empty == obs)
		return (1);
	if (empty == fill)
		return (1);
	if (obs == fill)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_error(void)
{
	write(2, "map error\n", 10);
}
