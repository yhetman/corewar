/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:00:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 04:11:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		j;

	j = -1;
	if (!(ret = (char *)malloc(sizeof(*ret) * LEN(src) + 1)))
		return (NULL);
	while (src[++j])
		ret[j] = src[j];
	ret[j] = '\0';
	return (ret);
}
