/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:29:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/09 22:02:31 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool	find_commands(char ***stored, t_assembler *ass)
{
	int		line;
	int		command;

	line = 1;
	while (stored[++line])
	{
		if (!stored[line][0])
			;
		else if (stored[line][0][0] == COMMENT_CHAR)
		{
			command = 0;
			while (stored[line][0][++command])
				if (!ft_strchr(COMMENT_CHARS, stored[line][0][command]))
						return (great_freeing(ass, NULL));
		}
		else if (stored[line][0])
			if (!get_command_info(ass, line))
				return (false);
	}
	return (true);
}

static bool	find_matches(char *line, char *buffer, char *string, int length)
{
	int		i;
	int		j;
	int		k;

	k = ft_strlen(line);
	if (!line || !ft_strnstr(line, string, ft_strlen(string)))
		return (false);
	i = ft_strlen(string);
	while (line[i] && IS_BLANK(line[i]))
		i++;
	if (!line[i] || k - i - (int)ft_strlen(string - 2 - 1) > length)
		return (false);
	if (i == (int)ft_strlen(string) ||
			IS_QOUTE(line[i]) || IS_QOUTE(line[k - 1]))
		return (false);
	j = -1;
	while (++i < k - 1)
	{
		if (!ft_strchr(COMMAND_CHARS, line[i]))
			return (false);
		buffer[++j] = line[i];
	}
	buffer[++j] = '\0';
	return (true);
}

int			file_checker(t_assembler *ass, t_header *head)
{
	int		i;

	i = -1;
	ft_bzero(head, sizeof(t_header *));
	if (!find_matches(ass->stored[0][0], head->prog_name,
				NAME_CMD_STRING, PROG_NAME_LENGTH))
		return (false);
	if (!find_matches(ass->stored[1][0], head->comment,
				COMMENT_CMD_STRING, COMMENT_LENGTH))
		return (false);
	if (!find_commands(ass->stored, ass))
		return (false);
	return (1);
}
