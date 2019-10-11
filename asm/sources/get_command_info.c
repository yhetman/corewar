/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:34:20 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/11 19:24:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		define_command_or_comment(int *i, int *j, char **line)
{
	if (!line[0])
		return (1);
	if (line[0] && ft_strchr(line[0], LABEL_CHAR) &&
		(validate_token(line[0]) == 1))
	{
		(*i)++;
		if (!line[1])
			return (1);
	}
	if (line[*i] && line[*i][0] == COMMENT_CHAR)
	{
		if (line[*i + 1])
			return (false);
		while (line[1][*j])
		{
			if (!ft_strchr(LABEL_CHARS, line[1][*j]))
				return (false);
			(*j)++;
		}
		return (1);
	}
	if (!line[*i])
		return (false);
	return (2);
}

static bool		get_info(t_command *command, char **line)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	if (!(result = define_command_or_comment(&i, &sign, line))
			|| result == 1)
		return (result);
	if (!(command->command = ft_strdup(line[i])))
		return (false);
	if (!line[++i] || (!(command->args = ft_strdup(line[i]))))
		return (false);
	if (!line[++i])
		return (true);
	if (line[i][0] != COMMENT_CHAR || line[i + 1])
		return (false);
	while (line[i][++sign])
		if (ft_strchr(COMMENT_CHARS, line[i][sign]))
			return (false);
	return (true);
}

int				get_command_info(t_assembler *ass, int count)
{
	t_command	command;
	int			index;

	ft_bzero(&command, sizeof(t_command));
	if (!get_info(&command, ass->stored[index]))
		return (false);
	return (1);
}
