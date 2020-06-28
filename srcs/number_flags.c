/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:50:39 by orantane          #+#    #+#             */
/*   Updated: 2020/03/12 15:21:38 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*do_plus(t_data *data)
{
	if (data->plus == 1 && data->num_val > -1 &&
		data->conversion_flag != 'u')
	{
		write(1, "+", 1);
		data->len++;
	}
	else if (data->space == 1 && data->num_val > -1 &&
			data->conversion_flag != 'u')
	{
		write(1, " ", 1);
		data->len++;
	}
	return (data);
}

static t_data	*handle_width_right(t_data *data)
{
	while (data->field_width > data->precision && data->field_width >
			data->num_len)
	{
		if (data->zero == 1 && data->precision != 0 && data->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->field_width--;
		data->len++;
	}
	return (data);
}

static t_data	*handle_width(t_data *data)
{
	if (data->minus == 0)
	{
		while (data->field_width > data->precision && data->field_width >
				data->num_len)
		{
			if (data->zero == 1 && data->precision != 0 && data->negative != 1
				&& data->precision < data->num_len)
			{
				write(1, "0", 1);
			}
			else
				write(1, " ", 1);
			data->field_width--;
			data->len++;
		}
	}
	return (data);
}

static t_data	*number_flags_cont(t_data *data, char *str)
{
	if ((data->plus == 1 || data->space == 1) && data->negative == 0)
		data->field_width -= 1;
	if (data->zero == 1 && data->hex == 0 && data->negative == 1 &&
		data->conversion_flag != 'u')
	{
		write(1, "-", 1);
		data->len++;
		data->field_width--;
		data->negative = 0;
		data->num_len--;
		str++;
	}
	if (data->zero == 1)
		data = do_plus(data);
	data = handle_width(data);
	if (data->zero == 0)
		data = do_plus(data);
	data = do_precision(data);
	if (data->negative == 1)
		str++;
	data = print_number(data, str);
	if (data->minus == 1)
		data = handle_width_right(data);
	return (data);
}

t_data			*number_flags(t_data *data, char *str)
{
	data->num_len = (int)ft_strlen(str);
	if (data->conversion_flag != 'u')
		data->num_val = ft_atoi(str);
	if (data->num_val < 0)
		data->negative = 1;
	if (data->num_val == 0 && data->precision == 0 && data->hex == 0)
		data->num_len = 0;
	if (data->hash == 1 && str[0] != '0' && data->hex == 1)
	{
		data = handle_hashtag(data, str);
		return (data);
	}
	if (data->precision == 0 && data->num_val == 0 && data->hex == 0 &&
			data->plus == 0 && data->conversion_flag != 'd')
	{
		write(1, " ", 1);
		data->len++;
		data->field_width--;
	}
	if (data->precision == 0 && str[0] == '0' && data->hex == 1 &&
		data->hash == 0 && data->field_width > 0)
	{
		write(1, " ", 1);
		data->len++;
	}
	return (number_flags_cont(data, str));
}
