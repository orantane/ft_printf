/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/03/01 20:13:41 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*convert_d_i(t_data *data)
{
	char	*str;

	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = ft_itoa((char)va_arg(data->args, void *));
		else
			str = ft_itoa((short)va_arg(data->args, void *));
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = ft_itoa((long)va_arg(data->args, void *));
		else
			str = ft_itoa((long long)va_arg(data->args, void *));
	}
	else
		str = ft_itoa((int)va_arg(data->args, void *));
	data = number_flags(data, str);
	free(str);
	return (data);
}
