/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/03/01 20:16:24 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_c_width(t_data *data, char c, int i)
{
	int	len;

	len = 1;
	if (len < data->field_width && data->conversion[0] == '-')
	{
		ft_putchar(c);
		while (len < data->field_width)
		{
			write(1, " ", 1);
			data->len++;
			len++;
		}
	}
	else if (len < data->field_width && data->conversion[0] != '-')
	{
		while ((len + ++i) < data->field_width)
		{
			write(1, " ", 1);
			data->len++;
		}
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	data->len++;
	return (data);
}

t_data			*convert_c(t_data *data)
{
	int		x;
	int		i;
	char	c;

	i = -1;
	if (data->conversion_flag == '%')
		c = '%';
	else
	{
		x = va_arg(data->args, int);
		c = (unsigned char)x;
	}
	data = print_c_width(data, c, i);
	return (data);
}
