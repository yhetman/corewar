/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/28 17:30:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "op_function.h"
# include "op.h"

//static unsigned short	g_arg_code[3] = {
//	T_REG,
//	T_DIR,
//	T_IND
//};

typedef char			t_byte;

typedef ssize_t			t_read;

typedef struct			s_header
{
	unsigned int		magic;
	t_byte				*prog_name;
	int					prog_size;
	t_byte				*comment;
}						t_header;

typedef struct			s_champion
{
	long				id;
	t_header			*head;
	t_byte				*code;
	unsigned int		current_lives_num;
	unsigned int		previous_lives_num;
	t_read				cycle_live;
	struct s_champion		*next;
}						t_champion;

typedef struct			s_carriage
{
	unsigned long		champ;
	int					wait;
	long				next_op;
	long				registers[REG_NUMBER];
	long long			cycle_live;
	unsigned short		code;
	unsigned short		args[3];
	unsigned long		step;
	bool				carry;
	t_champion			*champion;
	struct s_carriage		*next;
}						t_carriage;

typedef struct			s_vm
{
	unsigned short		arena[MEM_SIZE];
	t_champion			*champs[MAX_PLAYERS];
	long				amount_of_champs;
	t_champion			*alive;
	t_carriage			*carriages;
	unsigned int		amount_of_carr;
	unsigned int		lives;
	t_read				cycles;
	t_read				cycles_to_die;
	t_read				cycles_after_check;
	size_t				checks;
	t_read				dump_cycle;
	int					dump_print_mode;
}						t_vm;

void			get_champions(int *ac, char ***av, t_vm *vm, t_champion **champs);
int				check_byte_code(t_champion *champ, int fd);
int				carriages_placement(t_vm *vm);
int				execute_champs_code(t_vm *vm);
void			usage(void);
void			vm_exit(char *msg, t_vm *vm);
bool			is_cor(const char *file);
void			code_validation(t_vm *vm, t_carriage *carr, t_op *option);
unsigned long	arg_length(unsigned char type, t_op *option);
unsigned long	count_step(t_carriage *carr, t_op *option);

/*
**		free functions block
*/

int				free_vm(t_vm *vm);
int				free_carriage(t_carriage *carriages);
int				free_champion(t_champion *champions);
int				print_result(t_vm *vm);

#endif
