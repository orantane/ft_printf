/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:50:39 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 17:27:05 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*number_flags_cont2(t_data *data, char *str)
{
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

static t_data	*number_flags_cont(t_data *data, char *str)
{
	if (data->precision == 0 && str[0] == '0' && data->hex == 1 &&
		data->hash == 0 && data->field_width > 0)
	{
		write(1, " ", 1);
		data->len++;
	}
	if ((data->plus == 1 || data->space == 1) && data->negative == 0)
		data->field_width -= 1;
	if (data->hex == 0 && data->negative == 1 && data->conversion_flag != 'u')
	{
		if (data->zero == 1 && data->precision == -1)
		{
			write(1, "-", 1);
			data->len++;
			data->field_width--;
			data->negative = 0;
			data->num_len--;
			str++;
		}
		else if (data->field_width > data->precision &&
				data->precision != -1 && data->precision >= data->num_len
				&& data->minus == 0)
			data->field_width--;
	}
	return (number_flags_cont2(data, str));
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
		data->plus == 0 && data->conversion_flag != 'd' &&
		data->conversion_flag != 'i')
	{
		write(1, " ", 1);
		data->len++;
		data->field_width--;
	}
	return (number_flags_cont(data, str));
}
