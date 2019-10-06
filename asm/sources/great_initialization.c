/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:49:16 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/06 23:58:07 by yhetman          ###   ########.fr       */
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
	int		str;

	str = 0;
	while (str < lines && ++i >= 0)
	{
		curr = 0;
		while (file[curr + i] && file[curr + i] != '\n')
			curr++;
		if (!(command[str] = ft_strnew(curr + 1)))
			return (false);
		curr = 0;
		while (file[i] && file[i] != '\n')
		{
			command[str][curr] = file[i];
			curr++;
			i++;
		}
		command[str][curr] = '\0';
		str++;
	}
	command[str] = '\0';
	return (true)
}

int			great_initialization(t_assembler *ass, int lines, char *file)
{
	if (!(ass->command = (char **)malloc(sizeof(char*) * (lines + 1))))
		return (0);
	if (!(init_command(ass->command, lines, file, -1)))
		return (great_freeing(ass, file));
	if (!(ass->stored = (char ***)malloc(sizeof(char**) * (lines+ 1))))
		return (0);
	if (!(init_details(ass->stored, ass->command)))
		return (great_freeing(ass, file));
	return (1);
}
