/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:05 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/18 20:16:12 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool	check_amount(char *args, t_op options)
{
	int		i;
	int		j;

	i = -1;
	j = 1;
	while (args[++i])
		if (args[i] == SEPARATOR_CHAR)
			j++;
	if (j != options.count_args)
		return (false);
	return (true);
}

int		get_command_arguments(t_assembler *ass, t_command *command, int index, int count)
{
	int	i;
	int	arg;

	i = 0;
	arg = 0;
	if (!check_amount(command->args, ass->options[index]))
		return (0);
	while (command->args[i] && arg < ass->options[index].count_args)
	{
		if (command->args[i] == 'r') //checking registers 
			return (0);
		else if (command->args[i] == DIRECT_CHAR) //checking directs
			return(0);
		else if (command->args[i] != DIRECT_CHAR && command->args[i] == 'r') //checking indirect
			return (0);
		if (ft_strchr(command->args + i, SEPARATOR_CHAR))
			i += ft_strchr(command->args + i, SEPARATOR_CHAR) - (command->args + i) +1;
		else
			i = ft_strlen(command->args);
		arg++;
	}
	return (1);
}
