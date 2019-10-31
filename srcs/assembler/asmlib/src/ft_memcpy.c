/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memspy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:55:28 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/22 13:55:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sr;
	char	*ds;

	sr = (char *)src;
	ds = (char *)dst;
	i = -1;
	while (++i < n)
		ds[i] = sr[i];
	return (dst);
}
