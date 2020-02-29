/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:27:33 by orantane          #+#    #+#             */
/*   Updated: 2020/02/29 20:02:48 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for field_width but not user errors, add it later.
*/

t_data	*fill_width(t_data *data)
{
	if (data->format[(data->i - 1)] != '.')
	{
		data->field_width = ft_atoi(&data->format[data->i]);
		while (data->format[data->i] < 58 && data->format[data->i] > 47)
		{
			data->conversion[data->j] = data->format[data->i];
			data->i++;
			data->j++;
		}
	}
	return (data);
}

/*
** Checks for precision and user errors with precision.
*/

t_data	*fill_precision(t_data *data)
{
	if (data->format[data->i] == '.')
	{
		data->conversion[data->j] = '.';
		data->j++;
		data->i++;
		data->precision = ft_atoi(&data->format[data->i]);
		while (data->format[data->i] < 58 && data->format[data->i] > 47)
		{
			data->conversion[data->j] = data->format[data->i];
			data->j++;
			data->i++;
		}
		if (data->precision == -1)
			data->conversion_error = 0;
	}
	return (data);
}

/* 
** No error checking in this function yet. Need to add it later.
*/

t_data	*fill_size(t_data *data)
{
	int		i;
	int		size;
	int		j;

	j = 0;
	i = -1;
	size = 6;
	while (--size)
	{
		if (data->size[++i] == data->format[data->i])
		{
			data->conversion[data->j] = data->format[data->i];
			data->conversion_size[j] = data->format[data->i];
			j++;
			data->j++;
			data->i++;
		}
	}
	return (data);
}

/*
** Conversion type checking. Also checks for user errors.
*/

t_data	*fill_type(t_data *data)
{
	int		i;
	int		found;

	i = -1;
	found = 0;
	while (data->type[++i])
	{
	 	if(data->type[i] == data->format[data->i])
		{
			data->conversion_flag = data->format[data->i];
			data->conversion[data->j] = data->format[data->i];
			data->j++;
			data->i++;
			found = 1;
		}
	}
	if (found == 0)
		data->conversion_error = 0;
	return (data);
}

t_data	*fill_flag(t_data *data)
{
	int		i;
	int		flag;

	flag = 6;
	data->i++;
	while (--flag)
	{
		i = -1;
		while (data->flags[++i])
		{
			if (data->flags[i] == data->format[data->i])
			{
				data->conversion[data->j] = data->format[data->i];
				data->i++;
				data->j++;
			}
		}
	}
	data = fill_flags(data);
	return (data);
}
