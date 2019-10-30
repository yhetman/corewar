/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/30 12:11:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "op.h"

typedef unsigned long	t_ulong;

typedef unsigned char	t_uchar;

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
	unsigned int		curr_live;
	unsigned int		prev_live;
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
	unsigned char		arena[MEM_SIZE];
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


long			next_op(long next_op_code);
void			long_into_bytes(unsigned char *arena, long addr, long value, long size);
long			check_option_params(t_vm *vm, t_carriage *car, bool turn,  unsigned short i);
long			bytes_into_long(const unsigned char *arena, long bytes, long size);
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
void			check_live_cycles(t_vm *vm);

t_carriage				*copy_carriage(t_carriage *car, long ptr);
t_carriage				*init_car(t_champion *champ, long next_op);

void					add_carriage(t_carriage **all, t_carriage *last);

void					op_live(t_vm *vm, t_carriage *next_op);
void					op_ld(t_vm *vm, t_carriage *next_op);
void					op_st(t_vm *vm, t_carriage *next_op);
void					op_add(t_vm *vm, t_carriage *next_op);
void					op_sub(t_vm *vm, t_carriage *next_op);
void					op_and(t_vm *vm, t_carriage *cursor);
void					op_or(t_vm *vm, t_carriage *cursor);
void					op_xor(t_vm *vm, t_carriage *cursor);
void					op_zjmp(t_vm *vm, t_carriage *cursor);
void					op_ldi(t_vm *vm, t_carriage *cursor);
void					op_sti(t_vm *vm, t_carriage *cursor);
void					op_fork(t_vm *vm, t_carriage *cursor);
void					op_lld(t_vm *vm, t_carriage *cursor);
void					op_lldi(t_vm *vm, t_carriage *cursor);
void					op_lfork(t_vm *vm, t_carriage *cursor);
void					op_aff(t_vm *vm, t_carriage *cursor);

typedef void			(*t_op_func)(t_vm *vm, t_carriage *carr);

static t_op_func		g_op_functions[17] = {
						NULL,
						op_live,
						op_ld,
						op_st,
						op_add,
						op_sub,
						op_and,
						op_or,
						op_xor,
						op_zjmp,
						op_ldi,
						op_sti,
						op_fork,
						op_lld,
						op_lldi,
						op_lfork,
						op_aff
};

#endif
