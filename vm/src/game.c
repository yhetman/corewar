/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:03:52 by user              #+#    #+#             */
/*   Updated: 2019/10/25 14:24:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 0},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 0},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 0},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};



static inline void	move_carriage(t_carriage *carriage)
{
	carriage->pc += carriage->carry;
	carriage->pc %= MEM_SIZE;
	carriage->carry = 0;
	ft_bzero(carriage->arg_type, 3);
}

static inline void	update_op_id(t_cw *cw, t_carriage *crnt_carriage)
{
	crnt_carriage->op_id = cw->map[crnt_carriage->pc];
	if (cw->map[crnt_carriage->pc] >= 1 && cw->map[crnt_carriage->pc] <= 16)
		crnt_carriage->cycles_to_wait = op_tab[crnt_carriage->op_id].cycles;
}

static inline void	perform_operation(t_carriage *carriage, t_cw *cw)
{
	t_op			*op;

	op = NULL;
	if (carriage->cycles_to_wait == 0)
		update_op_id(cw, carriage);
	if (carriage->cycles_to_wait > 0)
		carriage->cycles_to_wait--;
	if (carriage->cycles_to_wait == 0)
	{
		if (carriage->op_id >= 1 && carriage->op_id <= 16)
		{
			op = &op_tab[carriage->op_id];
			parse_types(cw, carriage, op);
			if (check_arg_types(carriage, op) && check_args(carriage, cw, op))
				op->func(cw, carriage, op);
			else
				carriage->carry += update_carry(carriage, op);
		}
		else
			carriage->carry = 1;
		move_carriage(carriage);
	}
}

void				start_game(t_cw *cw)
{
	t_carriage	*crnt_carriage;

	while (cw->num_carriages)
	{
		print_map(cw->map);
		if (cw->cycles_to_dump == cw->cycles)
		{
			print_map(cw->map);
			exit(0);
		}
		++cw->cycles && cw->cycles_after_check++;
		crnt_carriage = cw->carriage;
		while (crnt_carriage)
		{
			perform_operation(crnt_carriage, cw);
			crnt_carriage = crnt_carriage->next;
		}
		if (cw->cycles_to_die == cw->cycles_after_check
						|| cw->cycles_to_die <= 0)
			check_cycles_to_die(cw);
	}
}
