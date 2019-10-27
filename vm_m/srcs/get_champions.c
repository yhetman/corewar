/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 03:12:35 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 16:42:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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

static void			init_each_champion(t_champion *champs, t_vm *vm, long id, char *file)
{
	t_champion		*new_champ;
	int				fd;

	if (!(new_champ = (t_champion*)malloc(sizeof(t_champion))))
			vm_exit("ERROR! Malloc failed!", &vm);
	ft_bzero(new_champ, sizeof(t_champion));
	if (!(new_champ->head = (t_header*)malloc(sizeof(t_header))))
		vm_exit("ERROR! Malloc failed!", &vm);
	ft_bzero(new_champ->head, sizeof(t_header));
	new_champ->id = id;
	if ((fd = open(file, O_RDONLY)) == -1)
		vm_exit("ERROR! File reading failed", &vm);
	if (!(check_byte_code(new_champ, fd)))
		vm_exit("EROOR! Player contains invalid bytecode", &vm);
   	new_champion(champs, new_champ);
	vm->amount_of_champs++;
}

void				get_champions(int *ac, char ***av, t_vm *vm, t_champion **champs)
{
	long			id;

	id = 0;
	if (*ac >= 3 && !ft_strcmp(**av, "-n"))
	{
		if (!IS_INT(*(*av + 1))
		|| (id = ft_atoi(*(*av + 1))) < 1
		|| id > MAX_PLAYERS
		|| check_champions_list(*champs, id)
		|| !is_cor(*(*av + 2)))
			usage();
		init_each_champion(champs, vm, id, *(*av + 2))
		(*ac) -= 3;
		(*av) += 3;
	}
	else if (is_cor(**argv))
	{
		init_each_champion(champs, vm, id, **av);
		(*ac)--;
		(*av)++;
	}
	else
		usage();
}
