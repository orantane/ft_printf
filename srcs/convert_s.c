/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/03/01 20:14:43 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data		*print_s_width(t_data *data, size_t s_len, char *s)
{
	int len;
	int i;

	i = -1;
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
	else
		ft_putstr(s);
	return (data);
}

t_data			*convert_s(t_data *data)
{
	int		i;
	size_t	len;
	char	*s;
	int		no_pre;

	no_pre = -1;
	i = 0;
	s = va_arg(data->args, char *);
	if (data->precision > no_pre && s)
		s = ft_strndup(s, data->precision);
	if (data->precision == no_pre && s)
		s = ft_strdup(s);
	if (data->precision > no_pre && !s)
		s = ft_strndup(("\0"), data->precision);
	if (data->precision == no_pre && !s)
		s = ft_strdup("\0");
	len = ft_strlen(s);
	data = print_s_width(data, len, s);
	data->len = data->len + (int)len;
	free(s);
	return (data);
}
