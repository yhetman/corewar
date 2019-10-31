/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:29:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 19:48:35 by botkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*del_space(char *str)
{
	int		len;
	char	*out;
	int		i;

	i = 0;
	len = ft_strlen(str);
	out = (char *)malloc((sizeof(char) * len) + 1);
	out[len] = '\0';
	while (*str && i <= len)
	{
		if (!IS_TABUL(*str))
		{
			out[i] = *str;
			i++;
		}
		str++;
	}
	out[i] = '\0';
	return (out);
}

static bool	find_commands(t_assembler *ass)
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
	if (!find_matches(ass->stored[0][0], head->prog_name,
	NAME_CMD_STRING, PROG_NAME_LENGTH))
		return (false);
	if (!find_matches(ass->stored[1][0], head->comment,
	COMMENT_CMD_STRING, COMMENT_LENGTH))
		return (false);
	if (!ass->stored[2] || !find_commands(ass))
		return (false);
	return (1);
}
