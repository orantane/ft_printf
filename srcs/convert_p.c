/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 07:18:29 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data		*print_p_width(t_data *data, char *s, size_t s_len, int i)
{
	int		len;

	len = (int)s_len;
	if (len < data->field_width && data->conversion[0] == '-')
	{
		ft_putstr(s);
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
		ft_putstr(s);
	}
	else if (len >= data->field_width)
		ft_putstr(s);
	return (data);
}

t_data				*convert_p(t_data *data)
{
	char				*hex_str;
	unsigned long int	*ptr;
	unsigned long int	addr;
	size_t				len;
	int					i;

	i = -1;
	ptr = (unsigned long int *)va_arg(data->args, void *);
	addr = (unsigned long int)ptr;
	hex_str = ft_itoa_base(addr, 16, 'a');
	hex_str = ft_strjoin("0x", hex_str);
	len = ft_strlen(hex_str);
	data = print_p_width(data, hex_str, len, i);
	data->len += (int)len;
	return (data);
}
