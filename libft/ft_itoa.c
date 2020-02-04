/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:02:06 by orantane          #+#    #+#             */
/*   Updated: 2019/11/15 18:16:42 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	char	*make_string(int modulo, char *str, int n, int len)
{
	int		neg;
	int		i;

	neg = 1;
	i = len;
	if (n < 0)
	{
		neg = neg * -1;
		n = n * -1;
	}
	while (n != 0)
	{
		modulo = n % 10;
		str[--i] = modulo + '0';
		n = n / 10;
	}
	if (neg == -1)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}

static int		calculate_malloc(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				modulo;
	int				len;

	modulo = 0;
	if (n == -2147483648)
	{
		str = "-2147483648";
		str = ft_strdup(str);
		return (str);
	}
	if (n == 0)
	{
		str = "0";
		str = ft_strdup(str);
		return (str);
	}
	len = calculate_malloc(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = make_string(modulo, str, n, len);
	return (str);
}
