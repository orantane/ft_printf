/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   //printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:30:06 by orantane          #+#    #+#             */
/*   Updated: 2020/03/07 08:52:39 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char	str[] = "Hello";
	int		pos;
	char	*str1;
	char	*curr;
	char	*dub;
	int		value;
	int		len;
	double	d;
	double	copy;
	int		i;
	int		deci;
	int		pres;

	pres = 10;
	deci = 1;
	i = 0;
	dub = ft_strnew(100);
	pos = 0;
	d = 0;
	copy = d;
/*	while (d > 0)
	{
		d = d / 10;
		deci++;
	}
	d = copy;
	str1 = ft_itoa((int)copy);
	while (str1[i] != '\0')
	{
		dub[i] = str1[i];
		i++;
	}
	dub[i++] = '.';
	copy = copy - (int)copy;
	while (pres > 0)
	{
		copy = copy * 10;
		pres--;
	}
	//printf("Copy = %f\n", copy);
	pos = 0;
	str1 = ft_itoa((int)copy);
	while (str1[pos] != '\0')
	{
		dub[i] = str1[pos];
		i++;
		pos++;
	}*/
	//printf("Double = %.1f!\n", d);
	return (0);
}
