/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:21:06 by orantane          #+#    #+#             */
/*   Updated: 2020/01/29 12:31:34 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*converter(t_data *data)
{
	if (data->conversion_flag == 'c')
		data = convert_c(data);
	if (data->conversion_flag == 's')
		data = convert_s(data);
	if (data->conversion_flag == 'p')
		data = convert_p(data);
	if (data->conversion_flag == 'd')
		data = convert_d(data);
	if (data->conversion_flag == 'i')
		data = convert_i(data);
	return (data);
}
