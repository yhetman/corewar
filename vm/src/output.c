/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:01:56 by user              #+#    #+#             */
/*   Updated: 2019/09/25 21:57:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_start(t_cw *cw)
{
	int	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < cw->num_players)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i + 1,
			cw->player[i].code_size,
			cw->player[i].name,
			cw->player[i].comment);
}

void	print_map(unsigned char *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%0.4x : ", i);
		j = -1;
		while (++j < 64)
			ft_printf("%.2x ", map[i + j]);
		ft_printf("\n");
		i += 64;
	}
}

void	print_result(t_cw *cw)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", -(cw->last_player->id),
		cw->last_player->name);
}