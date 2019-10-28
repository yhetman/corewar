/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:13:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/28 18:24:20 by yhetman          ###   ########.fr       */
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
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct			s_champion
{
	long				id;
	t_header			*head;
	t_byte				code[CHAMP_MAX_SIZE];
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
int				execcute_champs_code(t_vm *vm); 
void			usage(void);
void			vm_exit(char *msg, t_vm *vm);
bool			is_cor(const char *file);
int				print_result(t_vm *vm);
void			check_live_cycles(t_vm *vm);

#endif
