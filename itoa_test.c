/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:29:35 by orantane          #+#    #+#             */
/*   Updated: 2020/02/04 17:45:21 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	int i = -12235230;
	char *str;

	str = ft_itoa_base(i, 16);
	//printf("Result for %d: %s\n", i, str);
	return (0);
}
