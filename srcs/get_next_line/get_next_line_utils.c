/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:33:11 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/04 11:33:33 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

char	*copy(char *s1, int *i, char *ret)
{
	while (s1[*i])
	{
		ret[*i] = s1[*i];
		(*i)++;
	}
	return (ret);
}