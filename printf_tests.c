/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:30:06 by orantane          #+#    #+#             */
/*   Updated: 2020/02/05 17:06:30 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	char	*str;
	int		i;
	void	*ptr;
	void	*add;

	ptr = "2";
	add = &ptr;
	i = 0;
	printf("This is text: %5p, add = %lu\n", ptr, (unsigned long int)add);
	return (0);
}
