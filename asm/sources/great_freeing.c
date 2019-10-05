/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:59:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/05 21:01:22 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	great_freeing(t_assembler *ass, char *line)
{
	free_commands(ass->command);
	free_stored_info(ass->stored);
	ft_strdel(&line);
}
