/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:34:20 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/20 19:24:55 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		free_command(t_command *command)
{
	if (DEBUG)
		printf("|file_checker| -> |free_command|\n");
	if (command->command)
		free(command->command);
	if (command->args)
		free(command->args);
}

static int		check_info(t_command *command, t_assembler *ass, int count)
{
	int			index;
	int			res;

	if (DEBUG)
		printf("|file_checker| -> |check_info|\n");
	if (command->command)
		index = define_index(ass->options, command->command);	
	if (DEBUG)
		printf("|command|--|%s|--|index|--|%d|\n", command->command, index);
	if (index < 1)
		return (0);
	if (command->args)
		res = get_command_arguments(ass, command, index, count);
	free_command(command);
	return (res);
}

static int		define_command_or_comment(char **line, int *i, int *j)
{
	if (DEBUG)
		printf("|get_info| -> |define_command_or_comment|\n");
	if (!line[0])
		return (1);
	if (line[0] && ft_strchr(line[0], LABEL_CHAR) &&
		(validate_token(line[0]) == 1 || true))
	{
		(*i)++;
		if (!line[1])
			return (1);
	}
	if (line[*i] && line[*i][0] == COMMENT_CHAR)
	{
		if (line[*i + 1])
			return (0);
		while (line[1][*j])
		{
			if (!ft_strchr(LABEL_CHARS, line[1][*j]))
				return (0);
			(*j)++;
		}
		return (1);
	}
	if (!line[*i])
		return (0);
	return (2);
}

static int		get_info(t_command *command, char **line)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	if (DEBUG)
		printf("|get_command_info| -> |get_info|\n");
	if (!(result = define_command_or_comment(line, &i, &sign))
			|| result == 1)
		return (result);
	if (!(command->command = ft_strdup(line[i])))
		return (0);
	i++;
	if (!line[i])
		return (0);
	if (!(command->args = ft_strdup(line[i])))
		return (0);
	if (DEBUG)
		printf("|command|--|%s|--|arguments|--|%s|\n", command->command, command->args);
	i++;
	if (!line[i])
		return (1);
	if (line[i][0] != COMMENT_CHAR || line[i + 1])
		return (0);
	while (line[i][++sign])
		if (!ft_strchr(COMMENT_CHARS, line[i][sign]))
			return (0);
	return (1);
}

int				get_command_info(t_assembler *ass, int count)
{
	t_command	command;

	if (DEBUG)
		printf("|file_checker| -> |get_command_info|\n");
	ft_bzero(&command, sizeof(t_command));
	if (get_info(&command, ass->stored[count]) == 0)
		return (false);
	if (!check_info(&command, ass, count))
		return (false);
	free_command(&command);
	return (1);
}
