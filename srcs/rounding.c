/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:47:38 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 17:55:08 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_double	*fix(t_double *dub, char size)
{
	if (dub->ld < 1 && size == 'L')
	{
		dub->fix = 1;
		dub->ld = dub->ld + 1;
	}
	else if (dub->d < 1)
	{
		dub->fix = 1;
		dub->d = dub->d + 1;
	}
	return (dub);
}

static char		*final_str(char *nbr, int len, int neg, t_double *dub)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = (int)ft_strlen(nbr);
	if (neg == 1)
		i++;
	str = ft_strnew(i + 2);
	i = 0;
	while (nbr[j] != '\0')
	{
		if (dub->fix == 1)
		{
			nbr[j] -= 1;
			dub->fix = 0;
		}
		if (i == len)
			str[i++] = '.';
		str[i++] = nbr[j++];
	}
	free(nbr);
	str[i] = '\0';
	return (str);
}

char			*do_rounding_l(char *str, t_double *dub, t_data *data, int len)
{
	char		*temp;
	long double	l_copy;

	dub = fix(dub, data->conversion_size[0]);
	while (--dub->pres > 0)
		dub->ld *= 10;
	l_copy = dub->ld - (long long int)dub->ld;
	l_copy = l_copy * 10;
	if ((int)l_copy > 5)
		dub->ld++;
	if ((int)l_copy == 5 && (int)dub->ld % 2 != 0 && dub->fix == 1 &&
		(int)dub->ld >= 100)
		dub->ld++;
	if ((int)l_copy == 5 && (int)dub->ld % 2 != 0 && dub->fix == 0)
		dub->ld++;
	temp = ft_itoa((long long int)dub->ld);
	dub = init_dub(dub, data);
	while (--dub->pres > 0)
		dub->ld = dub->ld / 10;
	str = ft_itoa((long long int)dub->ld);
	len = (int)ft_strlen(str);
	free(str);
	return (final_str(temp, len, data->negative, dub));
}

char			*do_rounding(char *str, t_double *dub, t_data *data, int len)
{
	char		*temp;
	double		copy;

	dub = fix(dub, data->conversion_size[0]);
	while (--dub->pres > 0)
		dub->d *= 10;
	copy = dub->d - (long long int)dub->d;
	copy = copy * 10;
	if ((int)copy > 5)
		dub->d++;
	if ((int)copy == 5 && (int)dub->d % 2 != 0 && dub->fix == 1 &&
		(int)dub->d >= 100)
		dub->d++;
	else if ((int)copy == 5 && (int)dub->d % 2 != 0 && dub->fix == 0)
		dub->d++;
	temp = ft_itoa((long long int)dub->d);
	dub = init_dub(dub, data);
	while (--dub->pres > 0)
		dub->d = dub->d / 10;
	str = ft_itoa((long long int)dub->d);
	len = (int)ft_strlen(str);
	free(str);
	return (final_str(temp, len, data->negative, dub));
}
