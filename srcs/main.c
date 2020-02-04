/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:05:36 by orantane          #+#    #+#             */
/*   Updated: 2020/01/29 15:32:13 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int		i;
	char	s1[] = "I'm a string!";
	char	s2[] = "Me too!";
	char	c = 'C';

	ft_printf("String -> %20.2s, another one  -> %.5s. Print char %c.\n", s1, s2, c);
	printf("What my printf produced. What real printf produces is below.\n");
	i = printf("String -> %20.2s, another one  -> %.5s. Print char %c.\n", s1, s2, c);
	printf("%d\n", i);
	return (0);
}
