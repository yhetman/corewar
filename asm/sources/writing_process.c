/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:13:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 13:47:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	write_arguments(t_assembler *ass, t_writer *writer, char **buffer, int fd)
{
	int		i;
	int		numb;

	i = 0;
	numb = -1;
	while (buffer[writer->token] && 
			++numb < ass->options[writer->command_index].count_args)
	{
		if (buffer[writer->token + 1][i] == REG_CHAR)
		{
			ft_putchar_fd(ft_atoi(buffer[writer->token + 1] + i + 1), fd);
			writer->cursor++;
		}
		else
			write_direct_indirect(ass, writer, buffer, i);
		while (buffer[writer->token + 1][i]
				&& buffer[writer->token + 1][i] != SEPARATOR_CHAR)
			i++;
		i++;
	}
	writer->token = 0;
}

static void	write_arg_type_bc(t_op options, int fd, char *str, int *cursor)
{
	int				i;
	unsigned char	byte_code;

	i = -1;
	byte_code = 0;
	while (++i < options.count_args)
	{
		if (str[0] == REG_CHAR)
			byte_code += (REG_CODE << ((3 - i) * 2));
		else if (str[0] == '%')
			byte_code += (DIR_CODE << ((3 - i) * 2));
		else
			byte_code += (IND_CODE << ((3 - i) * 2));
		str = ft_strchr(str, SEPARATOR_CHAR)
			? ft_strchr(str, SEPARATOR_CHAR) + 1 : str;
	}
	ft_putchar_fd(byte_code, fd);
	(*cursor)++;
}

int			writing_process(t_assembler *ass, t_writer *writer, char **buffer, int fd)
{
	if (ft_strchr(buffer[0], LABEL_CHAR))
		writer->token = 1;
	if (buffer[writer->token])
	{
		if ((writer->command_index = define_index(ass->options, buffer[writer->token])))
		{
			ft_putchar_fd(writer->command_index, fd);
			writer->cursor++;
		}
		else
			return (0);
		writer->curr_command = writer->cursor;
		if (ass->options[writer->command_index].args_bc)
			write_arg_type_bc(ass->options[writer->command_index], fd,
					buffer[writer->token + 1], &(writer->cursor));
	}
	write_arguments(ass, writer, buffer, fd);
	return (1);
}
