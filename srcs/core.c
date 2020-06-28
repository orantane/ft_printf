/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:45:35 by orantane          #+#    #+#             */
/*   Updated: 2020/06/28 06:36:44 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_data *data)
{
	char c;

	c = (const char)data->format[data->i];
	write(1, &c, 1);
}

t_data	*print_number(t_data *data, char *str)
{
	if (data->conversion_flag == 'o' && data->hash == 1 && str[0] == '0')
	{
		write(1, "0", 1);
		data->len++;
		return (data);
	}
	if (data->hex == 1 && data->precision != 0 && str[0] == '0')
	{
		write(1, "0", 1);
		data->len++;
		return (data);
	}
	if (data->num_val == 0 && data->precision != 0 && data->hex == 0)
	{
		write(1, "0", 1);
		data->len++;
	}
	else if (data->num_val != 0)
	{
		ft_putstr(str);
		data->len += (int)ft_strlen(str);
	}
	else if (data->hex == 1 && data->num_val == 0 && str[0] != '0')
	{
		ft_putstr(str);
		data->len += (int)ft_strlen(str);
	}
	return (data);
}

t_data	*print_text(t_data *data)
{
	if (!data->format)
		return (0);
	if (data->format[data->i] != '\0')
	{
		print_char(data);
		data->len++;
	}
	return (data);
}
