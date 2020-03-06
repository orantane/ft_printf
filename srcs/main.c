/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:05:36 by orantane          #+#    #+#             */
/*   Updated: 2020/03/06 06:09:48 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int		i;
	double	z = 2;
	long long int		x = 16;
	char	s1[] = "I'm a string!";
	char	s2[] = "Me too!";
	char	c = 'C';

	ft_printf("Int in hexa is: %#.4llX\n", x);
	i = printf("Int in hexa is: %#.4llX\n", x);
	printf("%ld\n", i);
	return (0);
}
