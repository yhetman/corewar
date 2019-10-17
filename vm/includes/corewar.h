/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 06:06:51 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/ft_printf/libft/libft.h"
# include "op.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>

# define ABS(X) (((X) < 0) ? (-(X)) : (X))
# define ID(X)				((X) - 1)
# define PL(i)				cw->player[i]

typedef struct s_player t_player;
typedef struct s_carriage t_carriage;
typedef struct s_cw t_cw;
typedef struct s_op			t_op;

typedef struct						s_player
{
	int						id;
	int						fd;
	int						code_size;
	char					code[MEM_SIZE];
	char					name[PROG_NAME_LENGTH + 1];
	char					comment[COMMENT_LENGTH + 1];
	size_t					crnt_lives;
	size_t					prev_lives;
	ssize_t					last_cycle_check;

};

typedef struct						s_carriage
{
	unsigned int			id;
	unsigned int			carrys : 1;
	unsigned int			carry;
	unsigned int			cycles_to_wait;
	ssize_t					last_cycle_check;
	unsigned char			op_id;
	unsigned char			arg_type[3];
	int						pc;
	int						reg[17];
	t_player				*player;
	struct s_carriage			*next;

};

typedef struct						s_cw
{
	bool					f_dump;
	bool					print_aff;
	unsigned char			map[MEM_SIZE];
	t_player				player[MAX_PLAYERS];
	t_player				*last_player;
	t_carriage					*carriage;
	int						num_players;
	size_t					num_lives;
	size_t					num_checks;
	size_t					num_carriages;
	size_t					prev_cycles_alive;
	ssize_t					cycles;
	ssize_t					cycles_to_dump;
	ssize_t					cycles_to_die;
	ssize_t					cycles_after_check;

};



typedef struct						s_op
{
	char					*name;
	unsigned char			num_args;
	unsigned char			arg_type[3];
	unsigned char			op_id;
	unsigned int			cycles;
	char					*description;
	bool					codage;
	int						label_size;
	void					(*func)(t_cw *, t_carriage *, t_op *);
};

t_carriage			*initialize_carriage(t_player *player, int pc);
void				add_carriage(t_carriage **list, t_carriage *new_carriage);
void				set_carriage(t_cw *cw);
t_cw				*init_cw(void);
void				parse_types(t_cw *cw, t_carriage *carriage, t_op *op);
void				check_cycles_to_die(t_cw *cw);
void				start_game(t_cw *cw);
void				print_start(t_cw *cw);
void				print_map(unsigned char *map);
void				print_result(t_cw *cw);
void				ft_abort(char *s);
int					ft_parse_n(int i, char **av, char **file_name, t_cw *cw);
void    		    parser(int ac, char **av, t_cw *cw);
int					calc_pos(int pos);
int					ft_read_data(const int fd, void *buf, const int nb);
unsigned int		ft_read_bnum(const int fd, const int cnum);
int					ft_read_num(char *src);
void				ft_fill_map(t_cw *cw, int pl_num);
int					carry_size(char arg_type, t_op *op);
unsigned int		update_carry(t_carriage *carriage, t_op *op);
int					check_arg_types(t_carriage *carriage, t_op *op);
int					check_args(t_carriage *carriage, t_cw *cw, t_op *op);

#endif