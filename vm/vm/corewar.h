/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:23:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/10/26 12:38:36 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdint.h>

/*
** Macroses
*/

# define INDEX(X)		((X) - 1)

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

typedef struct			s_champion
{
	long				id;
	char				*name;
	char				*comment;
	long				code_size;
	unsigned short		*code;
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

typedef struct			s_cursor
{
	unsigned long		id;
	bool				carry;
	int					wait;
	long				next_op;
	long				registers[REG_NUMBER];
	long long			cycle_live;
	unsigned short		op_code;
	unsigned short		args[3];
	unsigned long		step;
	t_champion			*champion;
	struct s_cursor		*next;
}						t_cursor;

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
	t_cursor			*cursors;
	unsigned int		amount_of_cursors;
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

static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = true,
		.args = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = true,
		.args = {T_REG, T_REG | T_IND, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = false,
		.args = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = false,
		.args = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = true,
		.args = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = true,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = false,
		.args = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = true,
		.args = {T_REG, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

/*
** Functions
*/

int32_t			get_op_arg(t_vm *vm,
							t_cursor *cursor,
							uint8_t index,
							t_bool mod);
t_cursor		*duplicate_cursor(t_cursor *cursor, int32_t addr);
void			parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op);
bool			is_arg_types_valid(t_cursor *cursor, t_op *op);
bool			is_args_valid(t_cursor *cursor, t_vm *vm, t_op *op);
uint32_t		calc_step(t_cursor *cursor, t_op *op);
uint32_t		step_size(uint8_t arg_type, t_op *op);
int32_t			bytecode_to_int32(const uint8_t *arena,
									int32_t addr,
									int32_t size);
void			int32_to_bytecode(uint8_t *arena,
									int32_t addr,
									int32_t value,
									int32_t size);

/*
** Init
*/
t_player				*init_player(int id);
t_cursor				*init_cursor(t_player *champ, int32_t next_op);
t_vm					*init_vm(void);
void					init_arena(t_vm *vm);
/*
** Parse
*/
void					parse_corewar_args(int argc, char **argv, t_vm *vm);
void					parse_vs_flag(int *argc, char ***argv, t_vm *vm);
void					parse_dump_flag(int *argc, char ***argv, t_vm *vm);
void					parse_show_flag(int *argc, char ***argv, t_vm *vm);
void					parse_aff_flag(int *argc, char ***argv, t_vm *vm);
void					parse_log_flag(int *argc, char ***argv, t_vm *vm);
t_player				*parse_champion(char *filename, int num);
/*
** Cursor
*/
void					set_cursors(t_vm *vm);
void					add_cursor(t_cursor **list, t_cursor *new);
/*
** Execute
*/
void					exec(t_vm *vm);
void					exec_cycle(t_vm *vm);
/*
** Execute Utils
*/
void					update_op_code(t_vm *vm, t_cursor *current);
void					move_cursor(t_vm *vm, t_cursor *cursor);
/*
** Find
*/
t_player				*find_player(t_player *list, int32_t id);
/*
** Free
*/
void					free_vm(t_vm **vm);
/*
** Utils
*/
void					terminate(char *s);
t_bool					is_filename(const char *filename, const char *ext);
int32_t					calc_addr(int32_t addr);
int8_t					get_byte(t_vm *vm, int32_t next_op, int32_t step);
void					cycles_to_die_check(t_vm *vm);
/*
** Print
*/
void					print_intro(t_player **champs, int32_t amount_of_champs);
void					print_last_alive(t_vm *vm);
void					usage();
void					print_arena(uint8_t *arena, int print_mode);
/*
** Log
*/
void					log_cycle(ssize_t cycle);
void					log_pc_movements(uint8_t *arena, t_cursor *cursor);
void					log_cursor_death(t_vm *vm, t_cursor *cursor);
void					log_cycles_to_die(ssize_t cyc_reminder);

#endif
