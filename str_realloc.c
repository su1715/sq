/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:01:40 by dha               #+#    #+#             */
/*   Updated: 2021/10/24 19:44:37 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int	*str_realloc(int *ptr, int sz, int new_sz)
{
	int	i;
	int	*new;

	i = 0;
	new = (int *) malloc(sizeof(int) * new_sz);
	while (i <= sz && i <= new_sz)
	{
		new[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new);
}
