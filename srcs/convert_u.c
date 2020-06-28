/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 03:21:47 by orantane          #+#    #+#             */
/*   Updated: 2020/06/28 06:44:28 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned long long int modulo, char *str,
							unsigned long long int n, unsigned int len)
{
	unsigned int	i;

	i = len;
	while (n != 0)
	{
		modulo = n % 10;
		str[--i] = modulo + '0';
		n = n / 10;
	}
	return (str);
}

static int	calculate_len(unsigned long long int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*make_string(unsigned long long int n)
{
	char					*str;
	unsigned long long int	modulo;
	unsigned int			len;

	modulo = 0;
	if (n == 0)
	{
		str = "0";
		str = ft_strdup(str);
		return (str);
	}
	len = calculate_len(n);
	str = ft_strnew(len);
	str = create_string(modulo, str, n, len);
	return (str);
}

t_data		*convert_u(t_data *data)
{
	char	*str;

	if (data->conversion_size[0] == 'h')
	{
		if (data->conversion_size[1] == 'h')
			str = make_string((unsigned char)va_arg(data->args, void *));
		else
			str = make_string((unsigned short)va_arg(data->args, void *));
	}
	else if (data->conversion_size[0] == 'l')
	{
		if (data->conversion_size[1] == 'l')
			str = make_string((unsigned long)va_arg(data->args, void *));
		else
			str = make_string((unsigned long long)va_arg(data->args, void *));
	}
	else
		str = make_string((unsigned int)va_arg(data->args, void *));
	if (data->precision == 0 && str[0] == '0')
		str[0] = '\0';
	data = number_flags(data, str);
	free(str);
	return (data);
}
