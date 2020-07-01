/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_flags_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:18:46 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 17:25:37 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*do_plus(t_data *data)
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

t_data		*handle_width_right(t_data *data)
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

t_data		*handle_width(t_data *data)
{
	if (data->minus == 0)
	{
		while (data->field_width > data->precision && data->field_width >
				data->num_len)
		{
			if (data->zero == 1 && data->precision == -1
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
