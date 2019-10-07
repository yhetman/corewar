/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:59:02 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 04:14:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

size_t	ft_strlen(const char *str)
{
	size_t j;

	j = 0;
	if (str == NULL)
		return (j);
	else
	{
		while (str[j] != '\0')
			j++;
		return (j);
	}
}
