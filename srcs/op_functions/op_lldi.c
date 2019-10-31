/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:24:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 16:54:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		op_lldi(t_vm *vm, t_carriage *car)
{
<<<<<<< HEAD:vm/srcs/op_functions/op_lldi.c
	long	val_1;
	long	val_2;
	long	reg;

	car->step += 2;
	val_1 = check_option_params(vm, car, true, 1);
	val_2 = check_option_params(vm, car, true, 2);
	reg = vm->arena[next_op(car->next_op + car->step)];
	car->registers[reg - 1] = bytes_into_long(vm->arena,
			car->next_op + (val_1 + val_2), DIR_SIZE);
	car->step++;
=======
	while (*str && (!IS_TABUL(*str)))
    {
        if (*str == SEPARATOR_CHAR)
        {
            str++;
            while (*str && IS_TABUL(*str))
                ++str;
        }
        str++;
    }
	return (str);
}

int			find_words(char *str)
{
	char	*tmp;
	int		words;

	words = 0;
	tmp = str;
	while (*tmp)
	{
		while (IS_TABUL(*tmp))
			++tmp;
		if (*tmp == ',')
            while (IS_TABUL(*tmp))
                ++tmp;
		else if (*tmp == COMMENT_CHAR)
			tmp = skip_word(tmp);
		else if (++words)
			tmp = skip_word(tmp);
	}
	return (words);
>>>>>>> assembler:asm/asmlib/src/find_words.c
}
