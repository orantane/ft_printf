/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:11:36 by orantane          #+#    #+#             */
/*   Updated: 2020/03/11 15:56:00 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static t_double	*init_dub(t_double *dub, t_data *data)
{
	double	zero;

	zero = 0;
	dub->rounded = 0;
	if (dub->ld != zero)
		dub->ld_copy = dub->ld;
	if (dub->d != zero)
		dub->d_copy = dub->d;
	if (data->precision == -1)
		dub->pres = 7;
	else
		dub->pres = data->precision + 1;
	return (dub);
}

static char		*check_rounding_new(char *str, t_double *dub)
{
	int			prec;
	double		copy;

	prec = dub->pres;
	if (dub->d_copy)
	{
		copy = dub->d_copy;
		copy = copy - (int)dub->d_copy;
		while (--prec)
		{
			copy = copy * 10;
			dub->d_copy = dub->d_copy * 10;
		}
		if ((int)copy != 0)
			copy = copy - (int)copy;
		copy = copy * 10;
		if (copy >= 5)
		{
			dub->d_copy += 1;
			str = ft_itoa(dub->d_copy);
		}
	}
	return (str);
}

static t_double	*check_rounding(t_double *dub)
{
	double		copy;
	long double	long_copy;

	if (dub->d_copy)
	{
		copy = dub->d_copy;
		copy = copy - (int)dub->d_copy;
		copy = copy * 10;
		if ((int)copy >= 5)
		{
			dub->d_copy++;
			dub->rounded = 1;
		}
	}
	if (dub->ld_copy)
	{
		long_copy = dub->ld_copy;
		if (((long_copy * 10) - (long int)dub->ld_copy) >= 5)
			dub->ld_copy += 1;
	}
	return (dub);
}

static t_double	*double_string_ld(t_double *dub, t_data *data)
{
	return (dub);
}

static char		*double_string_d(t_double *dub, t_data *data)
{
	char	*str;

	str = ft_itoa((long long int)dub->d_copy);
	if (dub->d_copy < 0)
		dub->d_copy = dub->d_copy * -1;
	str = check_rounding_new(str, dub);
	if (data->precision != 0)
		str = ft_strjoin(str, ".");
	dub->d_copy = dub->d_copy - (long long int)dub->d_copy;	
	dub->temp = check_rounding_new(dub->temp, dub);
	if (data->precision != 0)
		str = ft_strjoin(str, dub->temp);
	return (str);
}

t_data			*convert_f(t_data *data)
{
	t_double	*dub;
	char		*str;

	if (!(dub = (t_double*)malloc(sizeof(dub))))
		return (data);
	if (data->conversion_size[0] == 'L')
	{
		dub->ld = (va_arg(data->args, long double));
		dub = init_dub(dub, data);
		dub = double_string_ld(dub, data);
	}
	else
	{
		dub->d = (va_arg(data->args, double));
		dub = init_dub(dub, data);
		str = double_string_d(dub, data);
	}
	ft_putstr(str);
	//data = number_flags(data, dub->str);
//	data = double_flags(data, dub);
//	free(dub);
	return (data);
}
