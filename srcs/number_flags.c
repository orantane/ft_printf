/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:50:39 by orantane          #+#    #+#             */
/*   Updated: 2020/02/29 22:02:32 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// For next time, code 'd' and 'i' conversions. You can copy the code from convert_x.c
// file for the most part and just integrate the nuances in this file. If it's easy, 
// code the 'o' and 'u' flags as well.

// First I need to check for '-', then I need to check for x and X. Then I need to check
// for '#' in case of o, x and X, other cases check for '+'. Check for "space", it comes
// before a positive number. If '+' is present, "space" is ignored. Check for '0', if '-'
// is present, ignore '0'. If precision is specified, '0' is ignored.
//
// Precision is the maximum amount of numbers to be written. Padded with 0's if number is
// smaller than precision. Does not shrink the end result if precision is smaller than the
// end result.
//
// Field width is the minimum amount of space that needs to be written. Padded with spaces
// if the number is smaller than field width. Can be used with 0 flag.

static t_data	*handle_precision(t_data *data, char *str)
{
	int	pre;

	pre = data->precision;
	while (pre > (int)ft_strlen(str))
	{
		write(1, "0", 1);
		data->len++;
		pre--;
	}
	while (data->field_width > data->precision &&
			data->field_width > (int)ft_strlen(str))
	{
		if (data->zero == 0)
		{
			write(1, " ", 1);
			data->len++;
			data->field_width--;
		}
		else if (data->zero == 1)
		{
			write(1, "0", 1);
			data->len++;
			data->field_width--;
		}
	}
	data = print_number(data, str);
	return (data);
}

static t_data	*print_hashtag(t_data *data, char *str)
{
	int		str_len;

	str_len = (int)ft_strlen(str);
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
		data->len++;
	}
	return (data);
}

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

t_data			*number_flags(t_data *data, char *str)
{
	if (data->conversion_flag == 'o' || data->conversion_flag == 'X' ||
			data->conversion_flag == 'x')
	{
		if (data->hash == 1)
			data = print_hashtag(data, str);
	}
	if (data->minus == 1)
	{
		if (data->plus == 1 && str[0] != '-')
		{
			write(1, "+", 1);
			data->len++;
		}
		else if (data->space == 1)
		{
			write(1, " ", 1);
			data->len++;
		}
		data = print_number(data, str);
	}
	data = handle_precision(data, str);
	return (data);
}
