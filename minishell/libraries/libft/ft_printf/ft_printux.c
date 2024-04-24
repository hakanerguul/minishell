/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <opiltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:21:35 by opiltan           #+#    #+#             */
/*   Updated: 2023/01/27 10:20:49 by opiltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putx(size_t numb, char format)
{
	int	len;

	len = 0;
	if (numb == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (numb >= 16)
		len += ft_putx(numb / 16, format);
	if (format == 'x')
		len += ft_putchar("0123456789abcdef"[numb % 16]);
	else
		len += ft_putchar("0123456789ABCDEF"[numb % 16]);
	return (len);
}

int	ft_put_unsint(unsigned int numb)
{
	int	len;

	len = 0;
	if (numb == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (numb >= 10)
		len += ft_put_unsint(numb / 10);
	len += ft_putchar("0123456789"[numb % 10]);
	return (len);
}
