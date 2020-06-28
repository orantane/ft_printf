/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:13:13 by orantane          #+#    #+#             */
/*   Updated: 2020/06/10 21:12:53 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_hashtag(t_data *data)
{
	if (data->conversion_flag == 'x')
	{
		write(1, "0x", 2);
		data->len += 2;
	}
	else if (data->conversion_flag == 'X')
	{
		write(1, "0X", 2);
		data->len += 2;
	}
	else if (data->conversion_flag == 'o')
	{
		write(1, "0", 1);
		data->precision--;
		data->len++;
	}
	return (data);
}

t_data			*do_precision(t_data *data)
{
	int	pre;

	if (data->precision == 0)
		return (data);
	pre = data->precision;
	if (data->negative == 1 && data->hex == 0)
	{
		write(1, "-", 1);
		data->field_width--;
		data->len++;
		data->num_len--;
	}
	while (pre > data->num_len)
	{
		write(1, "0", 1);
		data->len++;
		pre--;
	}
	return (data);
}

static t_data	*do_field_width(t_data *data, char *str)
{
	if (str[0] != '0')
	{
		if (data->conversion_flag == 'o')
			data->field_width -= 1;
		else if (data->hex == 1)
			data->field_width -= 2;
	}
	while (data->field_width > data->num_len &&
			data->field_width > data->precision)
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

t_data			*handle_hashtag(t_data *data, char *str)
{
	if (data->minus == 0 && data->zero == 0)
		data = do_field_width(data, str);
	if (str[0] != '0')
		data = print_hashtag(data);
	if (data->minus == 0 && data->zero == 1)
		data = do_field_width(data, str);
	if (data->precision > 0)
		data = do_precision(data);
	if (str[0] != '0')
		data = print_number(data, str);
	if (str[0] == '0' && data->precision < 1)
	{
		write(1, "0", 1);
		data->len++;
	}
	if (data->minus == 1)
		data = do_field_width(data, str);
	return (data);
}
