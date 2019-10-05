/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:49:16 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/05 22:06:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool	init_command(char **command, int lines, char *file, int i)
{
	int		curr;

	while (lines-- >= 0 && ++i >= 0)
	{
		curr = 0;
		while (file[curr + i] && file[curr + i] != '\n')
			curr++;
		if (!(ass->command = ft_strnew(curr + 1)))
			return (false);
		curr = 0;
		while (file[i] && file[i] != '\n')
		{
			*ass->command[curr] = file[i];
			curr++;
			i++;
		}
		*ass->command[curr] = '\0';
		ass->command++;
	}
	ass->command = NULL;
	return (true)
}

int			great_initialization(t_assembler *ass, t_reader *reader, char *file)
{
	ass->command = NULL;
	ass->stored = NULL;
	if (!(ass->command = (char **)malloc(sizeof(char*) * reader->line + 1)))
		return (0);
	if (!(init_command(ass->command, reader->line, file, -1)))
		return (great_freeing(ass, file));
	
}
