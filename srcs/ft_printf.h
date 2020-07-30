/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:36:36 by orantane          #+#    #+#             */
/*   Updated: 2020/07/01 18:13:27 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_double
{
	int				fix;
	int				pres;
	double			d;
	long double		ld;
}					t_double;

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
	long long int	num_val;
	int				negative;
	int				hex;
	int				base;
	int				conversion_error;
	long int		precision;
	long int		field_width;
	va_list			args;
	char			conversion_flag;
	char			*conversion;
	char			*conversion_size;
	char			*flags;
	char			*type;
	char			*size;
	char			*d_str;
}					t_data;

long long int		ft_atoi(const char *str);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(unsigned long long int num, int base,
					int caps);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t x);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
t_data				*converter(t_data *data);
t_data				*convert_p(t_data *data);
t_data				*convert_s(t_data *data);
t_data				*convert_c(t_data *data);
t_data				*convert_d_i(t_data *data);
t_data				*convert_x(t_data *data, char *str);
t_data				*convert_b(t_data *data, char *str);
t_data				*convert_xc(t_data *data, char *str);
t_data				*convert_u(t_data *data);
t_data				*convert_f(t_data *data);
t_data				*format_struct(t_data *data);
t_double			*init_dub(t_double *dub, t_data *data);
t_data				*number_flags(t_data *data, char *str);
t_data				*double_flags(t_data *data, char *str);
t_data				*handle_hashtag(t_data *data, char *str);
t_data				*do_precision(t_data *data);
t_data				*handle_width(t_data *data);
t_data				*handle_width_right(t_data *data);
t_data				*do_plus(t_data *data);
t_data				*fill_flags(t_data *data);
t_data				*fill_struct(t_data *data);
t_data				*fill_type(t_data *data);
t_data				*fill_size(t_data *data);
t_data				*fill_precision(t_data *data);
t_data				*fill_width(t_data *data);
t_data				*fill_flag(t_data *data);
t_data				*print_text(t_data *data);
t_data				*print_number(t_data *data, char *str);
char				*do_rounding(char *str, t_double *dub, t_data *data,
					int len);
char				*do_rounding_l(char *str, t_double *dub, t_data *data,
					int len);
void				print_char(t_data *data);
int					ft_printf(const char *format, ...);

#endif
