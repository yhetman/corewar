/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:29:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/20 19:58:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool	find_commands( t_assembler *ass)
{
	int		line;
	int		i;

	line = 2;
	if (DEBUG)
		printf("|file_checker| -> |find_commands|\n");
	while (ass->stored[line])
	{
		if (!ass->stored[line][0])
			;
		else if (ass->stored[line][0][0] == COMMENT_CHAR)
		{
			i = 1;
			while (ass->stored[line][0][i])
			{
				if (!ft_strchr(COMMENT_CHARS, ass->stored[line][0][i]))
						return (great_freeing(ass, NULL));
				i++;
			}
		}
		else if (ass->stored[line][0])
			if (!get_command_info(ass, line))
				return (false);
		line++;
	}
	return (true);
}

static bool	find_matches(char *line, char *buffer, char *string, int length)
{
	int		i;
	int		j;
	int		k;

	
	if (DEBUG)
		printf("|file_checker| -> |find_matches|\n");
	k = ft_strlen(line);
	if (!line || !ft_strnstr(line, string, ft_strlen(string)))
		return (false);
	i = ft_strlen(string);
	while (line[i] && IS_BLANK(line[i]))
		i++;
	if (!line[i] || k - i - (int)ft_strlen(string) - 3 > length)
		return (false);	
	if (i == (int)ft_strlen(string) ||
			!IS_QOUTE(line[i]) || !IS_QOUTE(line[k - 1]))
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
	if (DEBUG)
		printf("|go_to_assembler| -> |file_checker|\n");
	ft_bzero(head, sizeof(t_header *));
	if (!find_matches(ass->stored[0][0], head->prog_name,
				NAME_CMD_STRING, PROG_NAME_LENGTH))
		return (false);
	if (!find_matches(ass->stored[1][0], head->comment,
				COMMENT_CMD_STRING, COMMENT_LENGTH))
		return (false);
	if (DEBUG)
		printf("|.name| -> |%s|\n|.comment| -> |%s|\n", head->prog_name, head->comment);
	if (!ass->stored[2] || !find_commands(ass))
		return (false);
	return (1);
}
