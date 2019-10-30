/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:vm/libft/srcs/ft_printf/print_char.c
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
=======
/*   Created: 2019/10/23 08:29:20 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/30 18:40:29 by botkache         ###   ########.fr       */
>>>>>>> assembler:asm/sources/init.c
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD:vm/libft/srcs/ft_printf/print_char.c
void		print_char(va_list ap)
=======
int				octet(long long numb)
{
	int i;

	i = 1;
	while (numb / 256 && i++)
		numb /= 256;
	return (i);
}

t_header		*init_t_header(void)
>>>>>>> assembler:asm/sources/init.c
{
	print_c(va_arg(ap, int));
}

void		print_c(int c)
{
	if (g_data.width > 1 && ft_strchr(g_data.flags, '-'))
	{
		ft_printf_put_char(c);
		while (g_data.width-- > 1)
			ft_printf_put_char(' ');
	}
	else
	{
		if (!ft_strchr(g_data.flags, '0'))
			while (g_data.width-- > 1)
				ft_printf_put_char(' ');
		else
			while (g_data.width-- > 1)
				ft_printf_put_char('0');
		ft_printf_put_char(c);
	}
}
