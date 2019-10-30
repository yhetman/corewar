/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:54:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 19:14:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

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
 
# define REG_CHAR				'r'

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!'()-+*&<>=/"
# define COMMENT_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!'()-+*&<>=/ {}[].,\t#$"
# define COMMAND_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!'()-+*&<>=/ ,"

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

typedef struct					s_op
{
	char						name[5];
	int							count_args;
	char						args_type[3];
	int							index;	
	unsigned int				cycles;
	char						description[50];
	unsigned int				args_bc;
	unsigned int				command_size;
}								t_op;
                                   	
typedef struct					s_header
{
  unsigned int					magic;
  char							prog_name[PROG_NAME_LENGTH + 1];
  unsigned int					prog_size;
  char							comment[COMMENT_LENGTH + 1];
}								t_header;

#endif
