/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:56:56 by orantane          #+#    #+#             */
/*   Updated: 2020/02/04 15:54:53 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev(char *str)
{
	size_t	i;
	char	*rev;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	rev = ft_strnew(len);
	while (len > 0)
	{
		rev[i] = str[len];
		i++;
		len--;
	}
	return (rev);
}

static char		*ft_hexa(int num, char *str)
{
	int		i;
	int		temp;

	i = 0;
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 55;
			i++;
		}
		num = num / 16;
	}
	return (str);
}

char		*ft_itoa_base(int num, int base)
{
	int		i;
	char	*str;
	size_t	len;

	len = 100;
	i = 0;
	if (base == 0)
		return (NULL);
	if (base == 10)
		return (ft_itoa(num));
	str = ft_strnew(len);
	if (base == 16)
		str = ft_hexa(num, str);
	return (str);
}
