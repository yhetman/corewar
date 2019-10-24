/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:07:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 21:33:00 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

void ft_puthex_fd(long long hex, int fd)
{
	if (hex >= 256)
	{
		ft_puthex_fd(hex / 256, fd);
		ft_puthex_fd(hex % 256, fd);
	}
	else
		ft_putchar_fd(hex, fd);
}

void ft_puthex_n_fd(long long hex, int fd, int len)
{
	if (len)
	{
		ft_puthex_n_fd(hex >> 8, fd, --len);
		ft_puthex_fd(hex & 0xFF, fd);
	}
}
