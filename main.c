/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:05:36 by orantane          #+#    #+#             */
/*   Updated: 2020/06/10 20:56:59 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>

int		main()
{
	int		i;
	int		d;
	int		a = 42;
	long double		z = 123;
	long long int		x = -399;
	char	s1[] = "I'm a string!";
	char	s2[] = "Me too!";
	char	c = 'C';

	d = ft_printf("%X", a);
	printf("\n");
	i = printf("%X", a);
	printf("\n%d ft, %d norm\n", d, i);
	return (0);
}
