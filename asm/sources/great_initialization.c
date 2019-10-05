/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:49:16 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/05 20:58:42 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	great_initialization(t_assembler *ass, t_reader *reader, char *file)
{
	ass->command = NULL;
	ass->stored = NULL;
	if (!(ass->command = (char **)malloc(sizeof(char*) * reader->line + 1)))
		return (0);
	if (init_command(ass, reader, file))
		return (great_freeing(ass, file));
}
