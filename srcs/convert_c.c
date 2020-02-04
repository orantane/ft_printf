/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:42:31 by orantane          #+#    #+#             */
/*   Updated: 2020/01/29 14:31:49 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*convert_c(t_data *data)
{
	int		i;
	int		x;
	char	c;

	i = 0;
	x = va_arg(data->args, int);
	c = (unsigned char)x;
	if (data->precision != 0 && c)
	{
		ft_putchar(c);
		data->len++;
	}
	return (data);
}
