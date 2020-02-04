/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:23:10 by orantane          #+#    #+#             */
/*   Updated: 2020/01/29 15:31:35 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_data	*fill_struct(t_data *data)
{
	int 	i;

	i = data->i + 1;	
	if (data->format[data->i] == '%' && data->format[i] == '%')
	{
		print_char(data);
		data->len++;
		data->i++;
	}
	else
	{
		data = fill_flag(data);
		data = fill_width(data);
		data = fill_precision(data);
		data = fill_size(data);
		data = fill_type(data);
		data = converter(data);
	}
	return (data);
}

t_data	*reformat_struct(t_data *data)
{
	int		i;

	i = -1;
	data->j = 0;
	data->precision = -1;
	data->field_width = 0;
	data->conversion_flag = '\0';
	while (++i < 51)
		data->conversion[i] = '\0';
	return (data);
}

t_data	*format_struct(t_data *data)
{
	int		i;

	i = -1;
	data->len = 0;
	data->i = 0;
	data->j = 0;
	data->conversion_error = 1;
	data->conversion_flag = '\0';
	data->precision = -1;
	data->field_width = 0;
	data->type = "cCsSpdDioOuUxXf";
	data->flags = "#0-+ ";
	data->size = "hlL";
	while (++i < 51)
		data->conversion[i] = '\0';
	return (data);
}

int		ft_printf(const char *format, ...)
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
	while (format[data->i] != '\0')
	{
		if (format[data->i] == '%')
		{
			data = reformat_struct(data);
			data = fill_struct(data);
		}
		data = print_text(data);
		data->i++;
	}
	ret = data->len;
	printf("Conversion string = %s, Precision = %ld, ret = %d.\n", data->conversion, data->precision, ret);
	va_end(data->args);
	free(data);
	return (ret);
}
