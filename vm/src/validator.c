/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:16:04 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:07:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int					carry_size(char arg_type, t_op *op)
{
	if (arg_type == T_REG)
		return (1);
	else if (arg_type == T_DIR)
		return (op->label_size);
	else if (arg_type == T_IND)
		return (2);
	return (0);
}

unsigned int		update_carry(t_carriage *carriage, t_op *op)
{
	int				i;
	unsigned int	carry;

	i = -1;
	carry = 1 + (op->codage ? 1 : 0);
	while (++i < op->num_args)
		carry += carry_size(carriage->arg_type[i], op);
	return (carry);
}


int			check_arg_types(t_carriage *carriage, t_op *op)
{
	int		i;

	i = -1;
	while (++i < op->num_args)
		if (!(carriage->arg_type[i] & op->arg_type[i]))
			return (0);
	return (1);
}

int			check_args(t_carriage *carriage, t_cw *cw, t_op *op)
{
	int				i;
	unsigned int	carry;
	char			r_id;

	i = -1;
	carry = 1 + (op->codage ? 1 : 0);
	while (++i < op->num_args)
	{
		r_id = cw->map[(carriage->pc + carry) % MEM_SIZE];
		if ((carriage->arg_type[i] == T_REG) && !(r_id >= 1 && r_id <= 16))
			return (0);
		carry += carry_size(carriage->arg_type[i], op);
	}
	return (1);
}