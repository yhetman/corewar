/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 09:48:50 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:01:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = s;
	while (*s)
		++s;
	while (s >= tmp)
	{
		if (*s == c)
			return ((char *)s);
		--s;
	}
	return (NULL);
}
