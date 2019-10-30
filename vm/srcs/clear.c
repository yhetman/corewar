/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/30 20:26:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int	free_champion(t_champion *champion)
{
	if (!champion)
		return (0);
	if (champion->head)
	{
		if (champion->head->prog_name)
			free(champion->head->prog_name);
		if (champion->head->comment)
			free(champion->head->comment);
		free(champion->head);
	}
	if (champion->code)
		free(champion->code);
	free(champion);
	return (0);
}

int	free_carriage(t_carriage *carriages)
{
	t_carriage	*head;

	if (!carriages)
		return (0);
	head = carriages->next;
	carriages->next = NULL;
	while (head)
	{
		carriages = head;
		head = head->next;
		free(carriages);
	}
	return (0);
}

int	free_vm(t_vm *vm)
{
	int	i;

	if (!vm)
		return (0);
	if (!(i = 0))
		while (i < 4)
			free_champion(vm->champs[i++]);
	if (vm->carriages)
		free_carriage(vm->carriages);
	free(vm);
	return (0);
}
