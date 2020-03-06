/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:50:39 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 05:28:59 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Next time: Handle cases with 0's as precision, field width and the numeric value.
//
// The current version was changed. Check statements with the data->num_val variable.
// Also handle negative values with precision. '-' -sign needs to be in front of
// the 0's the precision does. There is no function to print or check for negative
// value atm. Should go like this -> "if (data->num_val < 0) -> write(1, "-", 1);
// This is to be checked after field width and before precision.
// The number needs to be then converted to a positive number, or just don't print
// the first character if it is a minus and precision is larger than the num_len.
//
//
//
//
//
// First I need to check for '-', then I need to check for x and X. Then I need to check
// for '#' in case of o, x and X, other cases check for '+'. Check for "space", it comes
// before a positive number. If '+' is present, "space" is ignored. Check for '0', if '-'
// is present, ignore '0'. If precision is specified, '0' is ignored.
//
// Precision is the maximum amount of numbers to be written. Padded with 0's if number is
// smaller than precision. Does not shrink the end result if precision is smaller than the
// end result. The '#' flag with precision means that "0x" is before precision and is not
// calculated in the precision. So "0x15" with precision of 3 is "0x015".
//
// Field width is the minimum amount of space that needs to be written. Padded with spaces
// if the number/precision is smaller than field width. Can be used with 0 flag. 
// "^THIS MUST BE DONE FIRST^".
// After field width is printed as needed, we check for hashtag, then precision, then print
// the number. If '-' is present, we check this after everything. So simple if at the start
// to check for '-', then another at the end to check the opposite.

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

static t_data	*handle_width_right(t_data *data, char *str)
{
	while (data->field_width > data->precision && data->field_width >
			data->num_len)
	{
		if (data->zero == 1 && data->precision != 0)
			write(1, "0", 1);
		else
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
		while (data->field_width > data->precision && data->field_width >
				data->num_len)
		{
			if (data->zero == 1 && data->precision != 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			data->field_width--;
			data->len++;
		}
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
	data->num_len = (int)ft_strlen(str);
	data->num_val = ft_atoi(str);
	if (data->num_val < 0)
		data->negative = 1;
	if (data->num_val == 0 && data->precision == 0)
		data->num_len = 0;
	if (data->hash == 1 && data->num_val != 0 &&
			(data->conversion_flag == 'o' ||
			 data->conversion_flag == 'X' || data->conversion_flag == 'x'))
	{
		data = handle_hashtag(data, str);
		return (data);
	}
	if (data->precision == 0 && data->num_val == 0 && data->hex == 0 && data->plus == 0)
	{
		write(1, " ", 1);
		data->len++;
		data->field_width--;
	}
	if ((data->plus == 1 || data->space == 1) && data->negative == 0)
		data->field_width -= 1;
	if (data->zero == 1)
		data = do_plus(data, str);
	data = handle_width(data, str);
	if (data->zero == 0)
		data = do_plus(data, str);
	data = do_precision(data);
	if (data->negative == 1)
		str++;
	data = print_number(data, str);
	if (data->minus == 1)
		data = handle_width_right(data, str);
	return (data);
}
