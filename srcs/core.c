/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:45:35 by orantane          #+#    #+#             */
/*   Updated: 2020/01/28 15:01:49 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_data *data)
{
	char c;

	c = (const char)data->format[data->i];
	write(1, &c, 1);
}

t_data	*print_text(t_data *data)
{
	if (!data->format)
		return (0);
	if (data->format[data->i] != '\0')
	{
		print_char(data);
		data->len ++;
	}
	return (data);
}
