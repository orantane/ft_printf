/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:36:36 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 06:09:20 by orantane         ###   ########.fr       */
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
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
	int				num_len;
	int				num_val;
	int				negative;
	int				hex;
	int				base;
	int				conversion_error;
	long int		precision;
	long int		field_width;
	va_list			args;
	char			conversion_flag;
	char			conversion[50];
	char			*conversion_size;
	char			*flags;
	char			*type;
	char			*size;
}					t_data;

t_data				*converter(t_data *data);
t_data				*convert_p(t_data *data);
t_data				*convert_s(t_data *data);
t_data				*convert_c(t_data *data);
t_data				*convert_d_i(t_data *data);
t_data				*convert_x(t_data *data);
t_data				*convert_X(t_data *data);
t_data				*convert_o(t_data *data);
t_data				*convert_u(t_data *data);
t_data				*convert_f(t_data *data);
t_data				*format_struct(t_data *data);
t_data				*number_flags(t_data *data, char *str);
t_data				*handle_hashtag(t_data *data, char *str);
t_data				*do_precision(t_data *data);
t_data				*fill_flags(t_data *data);
t_data				*fill_struct(t_data *data);
t_data				*fill_type(t_data *data);
t_data				*fill_size(t_data *data);
t_data				*fill_precision(t_data *data);
t_data				*fill_width(t_data *data);
t_data				*fill_flag(t_data *data);
t_data				*print_text(t_data *data);
t_data				*print_number(t_data *data, char *str);
void				print_char(t_data *data);
int					ft_printf(const char *format, ...);


#endif
