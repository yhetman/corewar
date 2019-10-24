/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:29:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 19:14:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool	find_commands( t_assembler *ass)
{
	int		line;
	int		i;

	line = 2;
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
			if (!get_command_info(ass, line)) //get_command_info() return false if line == 3
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
	ft_bzero(head, sizeof(t_header *));
	if (!find_matches(ass->stored[0][0], head->prog_name, NAME_CMD_STRING, PROG_NAME_LENGTH))
	{
		return (false);
	}
	if (!find_matches(ass->stored[1][0], head->comment, COMMENT_CMD_STRING, COMMENT_LENGTH))
		return (false);
	if (!ass->stored[2] || !find_commands(ass)) //find_commands() return false
		return (false);
	return (1);
}
