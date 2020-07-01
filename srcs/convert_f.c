/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:11:36 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 17:12:36 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_double		*init_dub(t_double *dub, t_data *data)
{
	if (data->precision == -1)
		dub->pres = 7;
	else
		dub->pres = data->precision + 1;
	return (dub);
}

static t_data	*double_string_ld(t_double *dub, t_data *data)
{
	char		*temp;
	int			len;

	len = 0;
	if (dub->ld < (long double)0.000000000000000000)
	{
		dub->ld = dub->ld * -1;
		data->negative = 1;
		data->field_width--;
	}
	temp = ft_itoa((long long int)dub->ld);
	data->d_str = do_rounding_l(temp, dub, data, len);
	free(temp);
	return (data);
}

static t_data	*double_string_d(t_double *dub, t_data *data)
{
	char	*temp;
	int		len;

	len = 0;
	if (dub->d < (double)0.000000000000)
	{
		dub->d = dub->d * -1;
		data->negative = 1;
		data->field_width--;
	}
	temp = ft_itoa((long long int)dub->d);
	data->d_str = do_rounding(temp, dub, data, len);
	free(temp);
	return (data);
}

t_data			*convert_f(t_data *data)
{
	t_double	*dub;

	if (!(dub = (t_double*)malloc(sizeof(dub))))
		return (data);
	dub = init_dub(dub, data);
	dub->fix = 0;
	if (data->conversion_size[0] == 'L')
	{
		dub->ld = (va_arg(data->args, long double));
		data = double_string_ld(dub, data);
	}
	else
	{
		dub->d = (va_arg(data->args, double));
		data = double_string_d(dub, data);
	}
	data = double_flags(data, data->d_str);
	free(data->d_str);
	return (data);
}
