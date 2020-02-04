/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:36:36 by orantane          #+#    #+#             */
/*   Updated: 2020/02/03 18:53:02 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_data
{
	const char		*format;
	int				len;
	int				i;
	int				j;
	int				conversion_error;
	long int		precision;
	long int		field_width;
	va_list			args;
	char			conversion_flag;
	char			conversion[50];
	char			*flags;
	char			*type;
	char			*size;
}					t_data;

t_data				*converter(t_data *data);
t_data				*convert_p(t_data *data);
t_data				*convert_s(t_data *data);
t_data				*convert_c(t_data *data);
t_data				*convert_i(t_data *data);
t_data				*convert_d(t_data *data);
t_data				*print_s_width(t_data *data, size_t len, char *s);
t_data				*format_struct(t_data *data);
t_data				*print_text(t_data *data);
t_data				*fill_struct(t_data *data);
t_data				*fill_type(t_data *data);
t_data				*fill_size(t_data *data);
t_data				*fill_precision(t_data *data);
t_data				*fill_width(t_data *data);
t_data				*fill_flag(t_data *data);
void				print_char(t_data *data);
int					ft_printf(const char *format, ...);


#endif
