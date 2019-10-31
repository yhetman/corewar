/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:38:54 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 18:39:52 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

char	*ft_strchr(const char *s, int c)
{
	int		j;
	char	*str;

	str = (char *)s;
	if (c < 0)
		c = c + 256;
	if (c > 255)
		c = c - 256;
	j = -1;
	while (str[++j])
		if (str[j] == c)
			return (&str[j]);
	if (str[j] == c)
		return (&str[j]);
	return (NULL);
}
