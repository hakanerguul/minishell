/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:23:25 by opiltan           #+#    #+#             */
/*   Updated: 2022/02/14 19:24:35 by opiltan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_p;
	char	*src_p;

	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst == src)
		return (dst);
	if (src_p < dst_p)
	{
		while (len--)
			dst_p[len] = src_p[len];
		return (dst);
	}
	while (len--)
		*dst_p++ = *src_p++;
	return (dst);
}
