/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:01:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 14:01:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

unsigned long	arg_length(unsigned char type, t_op *option)
{
	if (type & T_IND)
		return (IND_SIZE);
	else if (type & T_REG)
		return (REG_LEN);
	else if (type & T_DIR)
		return (option->command_size);
	return (0);
}

unsigned long	count_step(t_carriage *carr, t_op *option)
{
	long			i;
	unsigned long	step;

	i = -1;
	step = 1 + (option->args_bc ? 1 : 0);
	while (++i < g_option[(carr->code - 1)].count_args)
		step += arg_length(carr->args[i], option);
	return (step);
}

bool	is_cor(const char *file)
{
	return ((file && ft_strlen(file) >= 4)
			? (!ft_strcmp(ft_strchr(file, '\0') - 4, ".cor"))
		 : (false));
}

void	vm_exit(char *msg, t_vm *vm)
{
	ft_putendl_fd(msg, 1);
	if (vm)
		free_vm(vm);
	exit(1);
}

void	usage()
{
	ft_printf("Usage: \n");
	ft_printf("\t{ ./corewar [-dump [nbr_cycles]]");
	ft_printf("[-n [number]] champion1.cor] ... }\n");
	exit(SUCCESS);
}

//inline int8_t	get_byte(t_vm *vm, int32_t next_op, int32_t step)
//{
//	return (vm->arena[calc_addr(next_op + step)]);
//}
