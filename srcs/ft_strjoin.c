/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:48:03 by orantane          #+#    #+#             */
/*   Updated: 2019/11/15 18:15:51 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	total;
	char	*fresh;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	total = len;
	len = ft_strlen(s2);
	total = total + len;
	if (!(fresh = (char *)malloc(sizeof(char) * total + 1)))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
		fresh[i++] = s1[len++];
	len = 0;
	while (s2[len] != '\0')
		fresh[i++] = s2[len++];
	fresh[i] = '\0';
	return (fresh);
}
