/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:30:06 by orantane          #+#    #+#             */
/*   Updated: 2020/02/29 21:15:13 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char	str[] = "Hello";
	int		i;
	int		x;
	
	x = 353;
	i = (int)ft_strlen(str);
	printf("This is i % .5d\n", x, i);
	return (0);
}
