/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:05 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/18 21:31:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static bool get_register(char *args, t_op options, int index)
{
	int		i;

	i = 0;
	if ((T_REG & options.args_type[index]) != T_REG)
		return (false);
	while (args[++i] && args[i] != SEPARATOR_CHAR)
		if (!IS_DIGIT(args[i]) || i > 3)
			return (false);
	if (ft_atoi(args + 1) <= 0 || ft_atoi(args + 1) > REG_NUMBER)
		return (false);
	return (true);
}

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
		if (command->args[i] == 'r' && !(get_register(command->args + i, ass->options[index], arg))
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