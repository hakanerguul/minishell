/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:47:32 by opiltan           #+#    #+#             */
/*   Updated: 2022/02/14 17:49:12 by opiltan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	buff_c;
	size_t			i;

	buff = (unsigned char *)s;
	buff_c = c;
	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			if (buff[i] == buff_c)
				return ((char *)&buff[i]);
			i++;
		}
	}
	return (NULL);
}
