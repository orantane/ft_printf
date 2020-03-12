/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:47:38 by orantane          #+#    #+#             */
/*   Updated: 2020/03/12 15:21:16 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*final_str(char *nbr, int len, int neg)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = (int)ft_strlen(nbr);
	if (neg == 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (nbr[j] != '\0')
	{
		if (neg == 1)
		{
			str[i++] = '-';
			neg = 0;
		}
		if (i == len)
			str[i++] = '.';
		str[i++] = nbr[j++];
	}
	str[i] = '\0';
	return (str);
}

char		*do_rounding(char *str, t_double *dub, t_data *data, int len)
{
	char		*temp;
	double		copy;
	long double	l_copy;

	while (--dub->pres > 0)
		dub->d_copy *= 10;
	if (data->conversion_size[0] == 'L')
	{
		l_copy = dub->ld_copy - (int)dub->ld_copy;
		l_copy = l_copy * 10;
		if ((int)l_copy >= 5)
			dub->ld_copy++;
		temp = ft_itoa((long long int)dub->ld_copy);
	}
	else
	{
		copy = dub->d_copy - (int)dub->d_copy;
		copy = copy * 10;
		if ((int)copy >= 5)
			dub->d_copy++;
		temp = ft_itoa((long long int)dub->d_copy);
	}
	str = final_str(temp, len, dub->neg);
	return (str);
}
