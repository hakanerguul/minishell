/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:14:31 by opiltan           #+#    #+#             */
/*   Updated: 2022/02/14 19:16:34 by opiltan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;
	unsigned int	i;

	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (buff_s1[i] != buff_s2[i])
			return ((unsigned char)buff_s1[i] - (unsigned char)buff_s2[i]);
		i++;
	}
	return (0);
}
