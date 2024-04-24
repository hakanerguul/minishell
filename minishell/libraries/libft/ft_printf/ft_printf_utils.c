/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opiltan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:59 by opiltan           #+#    #+#             */
/*   Updated: 2022/06/23 18:33:39 by opiltan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr(char *a)
{
	int	len;

	len = 0;
	if (!a)
		a = "(null)";
	while (a[len])
		write(1, &a[len++], 1);
	return (len);
}

int	ft_putchar(char str)
{
	write(1, &str, 1);
	return (1);
}

int	ft_putnbr(int numb)
{
	unsigned int	index;

	index = 0;
	if (numb < 0)
	{
		ft_putchar('-');
		index = numb * -1;
	}
	else
		index = numb;
	if (index > 9)
		ft_putnbr(index / 10);
	ft_putchar(index % 10 + '0');
	return (ft_numb_len(numb));
}

size_t	ft_numb_len(int numb)
{
	int	len;

	len = 0;
	if (numb <= 0)
		len++;
	while (numb)
	{
		len++;
		numb = numb / 10;
	}
	return (len);
}
