/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:56:56 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 06:26:10 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev(char *str)
{
	size_t	i;
	char	*rev;
	size_t	len;

	i = -1;
	len = ft_strlen(str);
	rev = ft_strnew(len);
	while (len > 0)
		rev[++i] = str[--len];
	return (rev);
}

static char		*ft_hexa_caps(unsigned long long int num, char *str)
{
	int						i;
	unsigned long long int	temp;

	i = -1;
	while (num != 0)
	{
		temp = 0;
		temp = num % 16;
		if (temp < 10)
			str[++i] = temp + '0';
		else
			str[++i] = temp - 10 + 'A';
		num = num / 16;
	}
	return (ft_rev(str));
}

static char		*ft_hexa(unsigned long long int num, char *str, int base)
{
	int						i;
	unsigned long long int	temp;

	i = -1;
	while (num != 0)
	{
		temp = 0;
		temp = num % base;
		if (temp < 10)
			str[++i] = temp + '0';
		else
			str[++i] = temp - 10 + 'a';
		num = num / base;
	}
	return (ft_rev(str));
}

char			*ft_itoa_base(unsigned long long int num, int base, int caps)
{
	char	*str;
	size_t	len;

	len = 100;
	if (base == 0)
		return (NULL);
	if (num == 0)
		return (ft_itoa(num));
	if (base == 10)
		return (ft_itoa(num));
	str = ft_strnew(len);
	if (base == 16 && caps < 96)
		str = ft_hexa_caps(num, str);
	if (base == 16 || base == 8)
		str = ft_hexa(num, str, base);
	return (str);
}
