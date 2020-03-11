/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:16:10 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 07:27:52 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*convert_xc(t_data *data, char *str)
{
	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa_base((unsigned char)va_arg(data->args, void *),
					data->base, 'A');
		else
			str = ft_itoa_base((unsigned short)va_arg(data->args, void *),
					data->base, 'A');
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa_base((unsigned long long)va_arg(data->args, void *),
					data->base, 'A');
		else
			str = ft_itoa_base((unsigned long)va_arg(data->args, void *),
					data->base, 'A');
	}
	else
		str = ft_itoa_base((unsigned int)va_arg(data->args, void *),
				data->base, 'A');
	data = number_flags(data, str);
	return (data);
}

t_data	*convert_x(t_data *data, char *str)
{
	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa_base((unsigned char)va_arg(data->args, void *),
					data->base, 'a');
		else
			str = ft_itoa_base((unsigned short)va_arg(data->args, void *),
					data->base, 'a');
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa_base((unsigned long long)va_arg(data->args, void *),
					data->base, 'a');
		else
			str = ft_itoa_base((unsigned long)va_arg(data->args, void *),
					data->base, 'a');
	}
	else
		str = ft_itoa_base((unsigned int)va_arg(data->args, void *),
				data->base, 'a');
	data = number_flags(data, str);
	return (data);
}
