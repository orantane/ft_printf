/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 15:18:19 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_c_cont(t_data *data, char c, int i, int len)
{
	while ((len + ++i) < data->field_width)
	{
		if (data->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->len++;
	}
	ft_putchar(c);
	return (data);
}

static t_data	*print_c_width(t_data *data, char c, int i, int len)
{
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
		data = print_c_cont(data, c, i, len);
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
	int		len;

	len = 1;
	i = -1;
	if (data->conversion_flag == '%')
		c = '%';
	else
	{
		x = va_arg(data->args, int);
		c = (unsigned char)x;
	}
	data = print_c_width(data, c, i, len);
	return (data);
}
