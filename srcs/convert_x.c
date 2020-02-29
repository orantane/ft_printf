/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:16:10 by orantane          #+#    #+#             */
/*   Updated: 2020/02/29 21:35:42 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Flags need to be handled after size and before precision. Field width is after precision.
// Flags need to be read into the struct, then handled in a seperate function or file. Could
// this be done so that it works for other conversions as well?

/*static t_data	*print_x(t_data *data, char *str)
{
	size_t	str_len;
	int		i;
	int		j;

	j = data->precision;
	i = 0;
	str_len = ft_strlen(str);
	while (j > data->field_width && j > (int)str_len)
	{
		write(1, "0", 1);
		data->len++;
		j--;
	}
	while (data->field_width > (int)str_len && data->field_width >
			data->precision && data->field_width > 0)
	{
		write(1, " ", 1);
		data->len++;
		data->field_width--;
	}
	data->len = data->len + (int)str_len;
	ft_putstr(str);
	return (data);
}
*/

static t_data	*convert_X(t_data *data, char *str)
{
	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa_base((unsigned char)va_arg(data->args, void *), 16, 'A');
		else
			str = ft_itoa_base((unsigned short)va_arg(data->args, void *), 16, 'A');
}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa_base((unsigned long long)va_arg(data->args, void *), 16, 'A');
		else
			str = ft_itoa_base((unsigned long)va_arg(data->args, void *), 16, 'A');
	}
	else
		str = ft_itoa_base((unsigned int)va_arg(data->args, void *), 16, 'A');
	data = number_flags(data, str);
	return (data);
}


t_data			*convert_x(t_data *data)
{
	char	*str;
	
	str = ft_strnew(50);
	if (data->conversion_flag == 'X')
	{
		data = convert_X(data, str);
		return (data);
	}
	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa_base((unsigned char)va_arg(data->args, void *), 16, 'a');
		else
			str = ft_itoa_base((unsigned short)va_arg(data->args, void *), 16, 'a');
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa_base((unsigned long long)va_arg(data->args, void *), 16, 'a');
		else
			str = ft_itoa_base((unsigned long)va_arg(data->args, void *), 16, 'a');
	}
	else
		str = ft_itoa_base((unsigned int)va_arg(data->args, void *), 16, 'a');
	data = number_flags(data, str);
	return (data);
}
