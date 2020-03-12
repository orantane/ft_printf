/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 08:49:53 by orantane          #+#    #+#             */
/*   Updated: 2020/03/12 16:06:16 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static t_data	*do_plus(t_data *data, char *str)
{
	if (data->plus == 1 && data->negative == 0)
	{
		write(1, "+", 1);
		data->len++;
	}
	else if (data->space == 1 && data->negative == 0)
	{
		write(1, " ", 1);
		data->len++;
	}
	return (data);
}

static t_data	*handle_width_right(t_data *data)
{
	while (data->field_width > data->num_len)
	{
		write(1, " ", 1);
		data->field_width--;
		data->len++;
	}
	return (data);
}

static t_data	*handle_width(t_data *data, char *str)
{
	if (data->minus == 0)
	{
		while (data->field_width > data->num_len)
		{
			if (data->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			data->field_width--;
			data->len++;
		}
	}
	return (data);
}

t_data		*double_flags(t_data *data, t_double *dub, char *str)
{
	data->num_len = (int)ft_strlen(str);
	data->num_val = ft_atoi(str);
	if (data->num_val < 0)
		data->negative = 1;
	if ((data->plus == 1 || data->space == 1) && str[0] != '-')
		data->field_width -= 1;
	if (data->zero == 1)
		data = do_plus(data, str);
	data = handle_width(data, str);
	if (data->zero == 0)
		data = do_plus(data, str);
	data = print_number(data, str);
	printf("\n%d is field width & num len = %d\n", data->field_width, data->num_len);
	if (data->minus == 1)
		data = handle_width_right(data);
	return (data);
}
