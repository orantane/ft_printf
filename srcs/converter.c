/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:21:06 by orantane          #+#    #+#             */
/*   Updated: 2020/03/12 15:29:12 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data			*fill_flags(t_data *data)
{
	int		i;

	i = 0;
	while (data->conversion[i] != '\0')
	{
		if (data->conversion[i] == '#')
			data->hash = 1;
		if (data->conversion[i] == '-')
			data->minus = 1;
		if (data->conversion[i] == '+')
			data->plus = 1;
		if (data->conversion[i] == ' ')
			data->space = 1;
		if (data->conversion[i] == '0')
			data->zero = 1;
		i++;
	}
	return (data);
}

static t_data	*converter_2(t_data *data)
{
	if (data->conversion_flag == 'c')
		data = convert_c(data);
	if (data->conversion_flag == 's')
		data = convert_s(data);
	if (data->conversion_flag == 'p')
		data = convert_p(data);
	if (data->conversion_flag == 'u')
		data = convert_u(data);
	if (data->conversion_flag == 'd' || data->conversion_flag == 'i')
		data = convert_d_i(data);
	return (data);
}

t_data			*converter(t_data *data)
{
	char *str;

	str = ft_strnew(50);
	if (data->conversion_flag == 'x')
	{
		data->hex = 1;
		data->base = 16;
		data = convert_x(data, str);
	}
	if (data->conversion_flag == 'X')
	{
		data->hex = 1;
		data->base = 16;
		data = convert_xc(data, str);
	}
	if (data->conversion_flag == 'o')
	{
		data->hex = 1;
		data->base = 8;
		data = convert_x(data, str);
	}
	if (data->conversion_flag == 'f')
		data = convert_f(data);
	return (converter_2(data));
}
