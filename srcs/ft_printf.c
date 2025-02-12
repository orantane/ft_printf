/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:23:10 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 18:04:20 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data			*fill_struct(t_data *data)
{
	data = fill_flag(data);
	data = fill_width(data);
	data = fill_precision(data);
	data = fill_size(data);
	data = fill_type(data);
	data = converter(data);
	return (data);
}

t_data			*reformat_struct(t_data *data)
{
	int		i;

	i = -1;
	data->j = 0;
	data->minus = 0;
	data->plus = 0;
	data->hash = 0;
	data->space = 0;
	data->zero = 0;
	data->hex = 0;
	data->base = 10;
	data->num_val = 1;
	data->conversion_error = 1;
	data->negative = 0;
	data->precision = -1;
	data->conversion_size = ft_strnew(4);
	data->conversion = ft_strnew(15);
	data->field_width = 0;
	data->conversion_flag = '\0';
	return (data);
}

t_data			*format_struct(t_data *data)
{
	data->len = 0;
	data->i = 0;
	data->type = "cCsSpdDioOuUxXfb%";
	data->flags = "#0+- ";
	data->size = "hhllL";
	return (data);
}

static t_data	*ft_printf_loop(t_data *data)
{
	while (data->format[data->i] != '\0')
	{
		if (data->format[data->i] == '%')
		{
			data = reformat_struct(data);
			data = fill_struct(data);
			free(data->conversion_size);
			free(data->conversion);
		}
		else
		{
			data = print_text(data);
			data->i++;
		}
	}
	return (data);
}

int				ft_printf(const char *format, ...)
{
	t_data	*data;
	int		ret;

	ret = 0;
	if (!format)
		return (-1);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	data->format = format;
	va_start(data->args, format);
	data = format_struct(data);
	data = ft_printf_loop(data);
	ret = data->len;
	va_end(data->args);
	free(data);
	return (ret);
}
