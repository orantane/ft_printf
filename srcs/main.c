/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:05:36 by orantane          #+#    #+#             */
/*   Updated: 2020/03/11 15:31:18 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int		i;
	double	z = -123.999999999;
	long long int		x = -399;
	char	s1[] = "I'm a string!";
	char	s2[] = "Me too!";
	char	c = 'C';

	ft_printf("Double is: %f <--My version.\n", z);
	i = printf("Double is: %f <--What it should be.\n", z);
	printf("%d\n", i);
	return (0);
}
