/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:56:56 by orantane          #+#    #+#             */
/*   Updated: 2020/02/05 16:48:23 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev(char *str, int neg)
{
	size_t	i;
	char	*rev;
	size_t	len;

	i = -1;
	len = ft_strlen(str);
	if (neg != 0)
	{
		rev = ft_strnew(len + 1);
		rev[++i] = '-';
	}
	else
		rev = ft_strnew(len);
	while (len > 0)
		rev[++i] = str[--len];
	return (rev);
}

static char		*ft_hexa(long int num, char *str, int neg)
{
	int			i;
	long int	temp;

	i = -1;
	if (num < 0)
	{
		num = num * -1;
		neg = 1;
	}
	while (num != 0)
	{
		temp = 0;
		temp = num % 16;
		if (temp < 10)
			str[++i] = temp + '0';
		else
			str[++i] = temp - 10 + 'a';
		num = num / 16;
	}
	return (ft_rev(str, neg));
}

char			*ft_itoa_base(long int num, int base)
{
	char	*str;
	size_t	len;
	int		neg;

	neg = 0;
	len = 100;
	if (base == 0)
		return (NULL);
	if (base == 10)
		return (ft_itoa(num));
	str = ft_strnew(len);
	if (base == 16)
		str = ft_hexa(num, str, neg);
	return (str);
}
