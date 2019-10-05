/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:49:16 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/05 23:53:22 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool init_details(char ***grid, char **lines)
{
	int		words;


	return (true);
}

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

int			great_initialization(t_assembler *ass, int lines, char *file)
{
	ass->command = NULL;
	ass->stored = NULL;
	if (!(ass->command = (char **)malloc(sizeof(char*) * lines + 1)))
		return (0);
	if (!(init_command(ass->command, lines, file, -1)))
		return (great_freeing(ass, file));
	if (!(ass->stored = (char ***)malloc(sizeof(char**) * (lines+ 1))))
		return (0);
	if (!(init_details(ass->stored, ass->command)))
		return (great_freeing(ass, file));
	return (1);
}
