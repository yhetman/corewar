/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:56:54 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 00:24:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	j;

	j = 0;
	while (s1[j] && s1[j] == s2[j])
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
