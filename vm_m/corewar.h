/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:23:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/10/27 02:20:36 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "libft.h"
# include "op.h"

/*
** Macroses
*/


# define OP_CODE_LEN	1
# define ARGS_CODE_LEN	1
# define REG_LEN		1

/*
** Log Levels
*/

# define LIVE_LOG			1
# define CYCLE_LOG			2
# define OP_LOG				4
# define DEATH_LOG			8
# define PC_MOVEMENT_LOG	16

/*
** Arg's type — Arg's code
*/

//static unsigned short	g_arg_code[3] = {
//	T_REG,
//	T_DIR,
//	T_IND
//};

/*
** Player
*/

/*
** id                 — id number of champ
** name               — champion's name
** comment            — champion's comment
** code_size          — size of champion's executable code
** code               — champion's executable code
** current_lives_num  — number of reports that champ is alive
**                      during current cyc_reminder period
** previous_lives_num — number of reports that champ is alive
**                      during previous cyc_reminder period
** cycle_live          — cycle's number, on which champ was assigned
**                      as alive last time
** next               — pointer to the next champ
*/

typedef char			t_byte;

typedef ssize_t			t_read;

typedef struct			s_champion
{
	long				id;
	t_header			*head;
	t_code				code[CHAMP_MAX_SIZE];
	unsigned int		current_lives_num;
	unsigned int		previous_lives_num;
	ssize_t				cycle_live;
	struct s_champion		*next;
}						t_champion;

/*
** Cursor
*/

/*
** id             — id number of cursor
** carry          — special flag
** op_code        — operator's code that is placed under cursor
** cycle_live      — cycle's number when live operator was executed last time
** wait — number of cycles that remains to wait
** args     - types of op's each argument
**                  before operator execution
** next_op             — address of the next operator to execute at memory
** step           — number of bytes to shift
** registers            — registers
** champ         — owner of cursor
** next           — pointer to the next cursor
*/

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

/*
** Virtual machine
*/

/*
** arena              — memory where champs are fighting
** champs            — list of champs
** amount_of_champs        — number of champs
** alive         — pointer to the last champ that was assigned as alive
** cursors            — list of cursors
** amount_of_cursors        — number of cursors
** lives          — number of executed live operators during of cycle_to_die
** cycles             — number of cycles that was passed after start
** cyc_reminder      — game parameter
** cycles_after_check — number of cycles that was passed after last rules check
** checks         — game parameter
** vs                 — visualizer
** dump_cycle         — cycle's number after which dump of arena will be created
** dump_print_mode    — print mode of dump (32/64 bytes per line)
** show_cycle         — number of cycles after which arena will be shown
** show_print_mode    — print mode of show (32/64 bytes per line)
** display_aff        — flag that reports display output of aff operator or not
** log                — number that reports about log level.
**                      If log is assigned as -1, it means that log doesn't
**                      display.
*/

typedef struct			s_vm
{
	unsigned short		arena[MEM_SIZE];
	t_champion			*champs[MAX_PLAYERS];
	long				amount_of_champs;
	t_champion			*alive;
	t_carriage			*carriages;
	unsigned int		amount_of_carr;
	unsigned int		lives;
	ssize_t				cycles;
	ssize_t				cyc_reminder;
	ssize_t				cycles_after_check;
	size_t				checks;
	ssize_t				dump_cycle;
	int					dump_print_mode;
	//ssize_t				show_cycle;
	//int					show_print_mode;
	//bool					display_aff;
	//int					log;
}						t_vm;

/*
** Operator
*/

/*
** name            — operator's name
** code            — operator's code
** args_num        — number of arguments
** args_types_code — flag which reports that operator has code of types
** args      — types of each argument
** modify_carry    — flag which reports that operator modifies carry
** t_dir_size      — size of T_DIR agrument.
** cycles          — cycles to execution of operator
** func            — pointer to function
*/
/*
typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	t_bool		args_types_code;
	uint8_t		args[3];
	t_bool		modify_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
	void		(*func)(t_vm *, t_cursor *);

}				t_op;
*/
/*
** Operators
*/

/*
** Functions
*/

void			op_live(t_vm *vm, t_cursor *next_op);
void			op_ld(t_vm *vm, t_cursor *next_op);
void			op_st(t_vm *vm, t_cursor *next_op);
void			op_add(t_vm *vm, t_cursor *next_op);
void			op_sub(t_vm *vm, t_cursor *next_op);
void			op_and(t_vm *vm, t_cursor *cursor);
void			op_or(t_vm *vm, t_cursor *cursor);
void			op_xor(t_vm *vm, t_cursor *cursor);
void			op_zjmp(t_vm *vm, t_cursor *cursor);
void			op_ldi(t_vm *vm, t_cursor *cursor);
void			op_sti(t_vm *vm, t_cursor *cursor);
void			op_fork(t_vm *vm, t_cursor *cursor);
void			op_lld(t_vm *vm, t_cursor *cursor);
void			op_lldi(t_vm *vm, t_cursor *cursor);
void			op_lfork(t_vm *vm, t_cursor *cursor);
void			op_aff(t_vm *vm, t_cursor *cursor);

/*
** Array
*/


int32_t			get_op_arg(t_vm *vm, t_cursor *cursor, uint8_t index,bool mod);
t_cursor		*duplicate_cursor(t_cursor *cursor, int32_t addr);
void			parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op);
bool			is_arg_types_valid(t_cursor *cursor, t_op *op);
bool			is_args_valid(t_cursor *cursor, t_vm *vm, t_op *op);
uint32_t		calc_step(t_cursor *cursor, t_op *op);
uint32_t		step_size(uint8_t arg_type, t_op *op);
int32_t			bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size);
void			int32_to_bytecode(uint8_t *arena, int32_t addr, int32_t value, int32_t size);
/*
** Init
*/
//t_cursor				*init_cursor(t_player *champ, int32_t next_op);
//t_vm					*malloc_vm(t-vm *vm);
//void					init_arena(t_vm *vm);
/*
** Parse
*/
//void					parse_corewar_args(int argc, char **argv, t_vm *vm);
//void					parse_vs_flag(int *argc, char ***argv, t_vm *vm);
//void					check_dump(int *argc, char ***argv, t_vm *vm);
//void					parse_show_flag(int *argc, char ***argv, t_vm *vm);
//void					parse_aff_flag(int *argc, char ***argv, t_vm *vm);
//void					parse_log_flag(int *argc, char ***argv, t_vm *vm);
t_champion				*get_champion(char *filename, int num);
/*
** Cursor
*/
//void					set_cursors(t_vm *vm);
//void					add_cursor(t_cursor **list, t_cursor *new);
/*
** Execute
*/
//void					exec(t_vm *vm);
//void					exec_cycle(t_vm *vm);
/*
** Execute Utils
*/
//void					update_op_code(t_vm *vm, t_cursor *current);
//void					move_cursor(t_vm *vm, t_cursor *cursor);
/*
** Find
*/
//t_player				*find_player(t_player *list, int32_t id);
/*
** Free
*/
//void					free_vm(t_vm **vm);
/*
** Utils
*/
void					vm_exit(char *s, t_vm **vm);
bool					is_cor(const char *filename);
//int32_t					calc_addr(int32_t addr);
//int8_t					get_byte(t_vm *vm, int32_t next_op, int32_t step);
//void					cycles_to_die_check(t_vm *vm);
/*
** Print
*/
void					print_intro(t_player **champs, int32_t amount_of_champs);
void					print_last_alive(t_vm *vm);
void					usage();
void					print_arena(uint8_t *arena, int print_mode);

#endif
