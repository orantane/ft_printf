/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 08:49:53 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 17:29:38 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*do_plus_d(t_data *data)
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

static t_data	*handle_width_right_d(t_data *data)
{
	while (data->field_width > data->num_len)
	{
		write(1, " ", 1);
		data->field_width--;
		data->len++;
	}
	return (data);
}

static t_data	*handle_width_d(t_data *data)
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

static t_data	*double_flags_cont(t_data *data, char *str)
{
	if (data->zero == 0)
	{
		if (data->negative == 1)
		{
			write(1, "-", 1);
			data->len++;
		}
		data = do_plus(data);
	}
	data = print_number(data, str);
	if (data->hash == 1 && data->precision == 0)
	{
		write(1, ".", 1);
		data->len++;
	}
	if (data->minus == 1)
		data = handle_width_right_d(data);
	return (data);
}

t_data			*double_flags(t_data *data, char *str)
{
	data->num_len = (int)ft_strlen(str);
	data->num_val = ft_atoi(str);
	if ((data->plus == 1 || data->space == 1) && data->negative == 0)
		data->field_width -= 1;
	if (data->negative == 1 && data->zero == 1)
	{
		write(1, "-", 1);
		data->len++;
	}
	if (data->hash == 1 && data->precision == 0)
		data->field_width--;
	if (data->zero == 1)
		data = do_plus_d(data);
	data = handle_width_d(data);
	data = double_flags_cont(data, str);
	return (data);
}
