/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:11:36 by orantane          #+#    #+#             */
/*   Updated: 2020/03/12 15:35:47 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_double	*init_dub(t_double *dub, t_data *data)
{
	double	zero;

	zero = 0;
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

static t_double	*double_string_ld(t_double *dub, t_data *data)
{
	char	*str;
	int		len;

	str = ft_itoa((long long int)dub->d_copy);
	len = (int)ft_strlen(str);
	if (dub->ld_copy < 0)
	{
		dub->ld_copy = dub->ld_copy * -1;
		dub->neg = 1;
	}
	else
		dub->neg = 0;
	str = do_rounding(str, dub, data, len);
	return (dub);
}

char			*double_string_d(t_double *dub, t_data *data)
{
	char	*str;
	int		len;

	str = ft_itoa((long long int)dub->d_copy);
	len = (int)ft_strlen(str);
	if (dub->d_copy < 0)
	{
		dub->d_copy = dub->d_copy * -1;
		dub->neg = 1;
	}
	else
		dub->neg = 0;
	str = do_rounding(str, dub, data, len);
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
	data = double_flags(data, dub, str);
	return (data);
}
