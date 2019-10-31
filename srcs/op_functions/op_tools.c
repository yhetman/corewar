/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:15:19 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/29 16:15:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_carriage(t_carriage **all, t_carriage *last)
{
	if (last)
		last->next = *all;
	*all = last;
}

t_carriage	*init_car(t_champion *champ, long next_op)
{
	t_carriage				*car;
	static unsigned long	champ_id;

	if (!(car = (t_carriage *)malloc(sizeof(t_carriage))))
		vm_exit(NULL, NULL);
	car->champ = ++champ_id;
	ft_bzero(car, sizeof(t_carriage));
	car->next_op = next_op;
	car->registers[0] = -(champ->id);
	car->champion = champ;
	return (car);
}

t_carriage	*copy_carriage(t_carriage *car, long ptr)
{
	t_carriage	*new;
	int			i;

	i = -1;
	ptr = next_op(car->next_op + ptr);
	new = init_car(car->champion, ptr);
	while (++i < REG_NUMBER)
		new->registers[i] = car->registers[i];
	new->carry = car->carry;
	new->cycle_live = car->cycle_live;
	return (new);
}
