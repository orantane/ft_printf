/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:07:26 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 18:12:40 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*convert_b(t_data *data, char *str)
{
	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa_base((unsigned char)va_arg(data->args, void *),
					2, 'a');
		else
			str = ft_itoa_base((unsigned short)va_arg(data->args, void *),
					2, 'a');
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa_base((unsigned long long)va_arg(data->args, void *),
					2, 'a');
		else
			str = ft_itoa_base((unsigned long)va_arg(data->args, void *),
					2, 'a');
	}
	else
		str = ft_itoa_base((unsigned int)va_arg(data->args, void *),
				2, 'a');
	data = number_flags(data, str);
	free(str);
	return (data);
}
