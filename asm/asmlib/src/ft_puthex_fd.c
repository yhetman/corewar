/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:07:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 18:13:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

void ft_puthex_fd(unsigned long long hex, int fd)
{
	if (hex < 256)
	{
		ft_puthex_fd(hex / 256, fd);
		ft_puthex_fd(hex % 256, fd);
	}
	else
		ft_putchar_fd(hex, fd);
}
