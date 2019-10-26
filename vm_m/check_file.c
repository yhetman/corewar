/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 03:12:35 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/26 15:10:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_champion	*check_champions_list(t_champion *all, long id)
{
	t_champion		*champ;

	champ = NULL;
	if (id < 1 || id > MAX_PLAYERS)
		return (NULL);
	champ = all;
	while (champ)
	{
		if (champ->id == id)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}

static void			new_champion(t_champion **all, t_champion *new)
{
	t_champion		*last;

	if (!all || !new)
		return ;
	if (*all)
	{
		last = *all;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*all = new;
}

static void			init_all_champions(t_champion *champs, long id, char *file)
{
	t_champion		*new_champ;
	int				fd;

	if (!(new_champ = (t_champion*)malloc(sizeof(t_champion))))
			vm_exit("ERROR! Malloc failed!", NULL);
	ft_bzero(new_champ, sizeof(t_champion));
	new_champ->id = id;
	if ((fd = open(file, O_RDONLY)) == -1)
		vm_exit("ERROR! File reading failed", NULL);
   	new_champion(champs, new_champ);
}

void	check_file(int *ac, char ***av, t_vm *vm, t_champion **champs)
{
	long	id;

	id = 0;
	if (*ac >= 3 && !ft_strcmp(**av, "-n"))
	{
		if (!IS_INT(*(*av + 1))
		|| (id = ft_atoi(*(*av + 1))) < 1
		|| id > MAX_PLAYERS
		|| check_champions_list(*champs, id)
		|| !is_cor(*(*av + 2)))
			usage();
		init_all_champions(champs, id, *(*av + 2))
		new_champion(champs, parse_champion(*(*av + 2), id));
		vm->amount_of_champs++;
		(*ac) -= 3;
		(*av) += 3;
	}
	else if (is_cor(**argv))
	{
		init_all_champions(champs, id, **av);
		new_champion(champs, parse_champion(**av, id));
		vm->amount_of_champs++;
		(*ac)--;
		(*av)++;
	}
	else
		usage();
	}
