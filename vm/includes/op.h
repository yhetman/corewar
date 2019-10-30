/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:32:47 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/30 16:46:14 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OP_H
# define _OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef char					t_arg_type;

typedef struct		s_op
{
	char			name[5];
	int				count_args;
	char			args[3];
	int				index;
	unsigned int	cycles;
	char			description[50];
	unsigned int	args_bc;
	unsigned int	command_size;
}					t_op;

static t_op						g_option[17] = {
	{
		.name = "\0",
		.count_args = 0,
		.args = "\0",
		.index = 0,
		.cycles = 0,
		.description = "\0",
		.args_bc = 0,
		.command_size = 0
	},
	{
		.name = "live",
		.count_args = 1,
		.args = {T_DIR},
		.index = 1,
		.cycles = 10,
		.description = "alive",
		.args_bc = 0,
		.command_size = 0,
	},
	{
		.name = "ld",
		.count_args = 2,
		.args = {T_DIR | T_IND, T_REG},
		.index = 2,
		.cycles = 5,
		.description = "load",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "st",
		.count_arga= 2,
		.args = {T_REG, T_IND | T_REG},
		.index = 3,
		.cycles = 5,
		.description = "store",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "add",
		.count_args = 3,
		.args = {T_REG, T_REG, T_REG},
		.index = 4,
		.cycles = 10,
		.description = "addition",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "sub",
		.count_args = 3,
		.args = {T_REG, T_REG, T_REG},
		.index = 5,
		.cycles = 10,
		.deescription = "soustraction",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "and",
		.count_args = 3,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.index = 6,
		.cycles = 6,
		.description = "et (and  r1, r2, r3   r1&r2 -> r3",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name ="or",
		.count_args = 3,
		.args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.index = 7,
		.cycles = 6,
		.description = "ou  (or   r1, r2, r3   r1 | r2 -> r3",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "xor",
		.count_args = 3,
		.args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.index = 8,
		.cycles = 6,
		.description = "ou (xor  r1, r2, r3   r1^r2 -> r3",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "zjmp",
		.count_args = 1,
		.args = {T_DIR},
		.index = 9,
		.cycles = 20,
		.description = "jump if zero",
		.args_bc = 0,
		.command_size = 1
	},
	{
		.name = "ldi",
		.count_args = 3,
		.args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.index = 10,
		.cycles = 25,
		.descriprion = "load index",
		.args_bc = 1,
		.command_size = 1
	},
	{
		.name = "sti",
		.count_args = 3,
		.args = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.index = 11,
		.cycles = 25,
		.description = "store index",
		.args_bc = 1,
		.command_size = 1
	},
	{
		.name = "fork",
		.count_args = 1,
		.args = {T_DIR},
		.index = 12,
		.cycles = 800,
		.description = "fork",
		.args_bc = 0,
		.command_size = 1
	},
	{
		.name = "lld",
		.count_args = 2,
		.args = {T_DIR | T_IND, T_REG},
		.index = 13,
		.cycles = 10,
		.description = "long load",
		.args_bc = 1,
		.command_size = 0
	},
	{
		.name = "lldi",
		.count_args = 3,
		.args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.index = 14,
		.cycles = 50,
		.description = "long load index",
		.args_bc = 1,
		.command_size = 1
	},
	{
		.name = "lfork",
		.count_args = 1,
		.args = {T_DIR},
		.index = 15,
		.cycles = 1000,
		.description = "long fork",
		.args_bc = 0,
		command_size = 1
	},
	{
		.name = "aff",
		.count_args = 1,
		.args = {T_REG},
		.index = 16,
		.cycles = 2,
		.description = "aff",
		.args_bc = 1,
		.command_size = 0
	}
};

#endif
