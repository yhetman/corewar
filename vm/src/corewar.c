/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 06:16:25 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:05:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error_manager.h"

t_carriage			*initialize_carriage(t_player *player, int pc)
{
	t_carriage		*carriage;
	static int	id;

	if (!(carriage = (t_carriage *)ft_memalloc(sizeof(t_carriage))))
		ft_abort(ERR_CARRIAGE_INIT);
	carriage->id = ++id;
	carriage->op_id = 0;
	carriage->carrys = false;
	carriage->pc = pc;
	carriage->last_cycle_check = 0;
	carriage->cycles_to_wait = 0;
	carriage->reg[1] = player->id;
	carriage->player = player;
	carriage->next = NULL;
	return (carriage);
}

void				add_carriage(t_carriage **list, t_carriage *new_carriage)
{
	if (new_carriage)
		new_carriage->next = *list;
	*list = new_carriage;
}

void				set_carriage(t_cw *cw)
{
	int				i;
	unsigned int	pos;

	i = 0;
	pos = 0;
	while (++i <= cw->num_players)
	{
		add_carriage(&(cw->carriage), initialize_carriage(&cw->player[i - 1], pos));
		cw->num_carriages++;
		pos += MEM_SIZE / cw->num_players;
	}
}


t_cw			*init_cw(void)
{
	t_cw	*cw;

	if (!(cw = (t_cw *)ft_memalloc(sizeof(t_cw))))
		ft_abort(ERR_CW_INIT);
    cw->f_dump = false;
	cw->print_aff = false;    
	cw->last_player = NULL;
	cw->carriage = NULL;
	cw->num_players = 0;
	cw->num_lives = 0;
	cw->num_checks = 0;
	cw->num_carriages = 0;
	cw->cycles = 0;
	cw->cycles_to_dump = -1;
	cw->cycles_to_die = CYCLE_TO_DIE;
	cw->cycles_after_check = 0;	
	return (cw);
}

int         main(int ac, char **av)
{
    t_cw    *cw;

    if (ac < 2)
        printf("No arguments");
    else
    {
        cw = init_cw();
        parser(ac--, av++, cw);
        set_carriage(cw);
        print_start(cw);
        start_game(cw);
        print_result(cw);
    }
    return (0);
}