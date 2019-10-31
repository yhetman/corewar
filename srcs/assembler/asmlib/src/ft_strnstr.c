/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:15:10 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/09 20:15:41 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char*)str);
	i = -1;
	while (str[++i] && i < n)
	{
		j = 0;
		while (to_find[j] && str[i + j] && (i + j) < n)
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (to_find[j] == 0)
			return ((char*)(str + i));
	}
	return (NULL);
}
