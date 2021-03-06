/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:01:44 by dha               #+#    #+#             */
/*   Updated: 2021/10/28 10:35:29 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

int		ft_min(int left, int up, int left_up);
int		ft_atoi(char *str);
int		is_overlap(char empty, char obs, char fill);
void	ft_error(void);
char	*ft_strcpy(char *dest, char *src);
int		*int_realloc(int *ptr, int sz, int new_sz);

#endif
