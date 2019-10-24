/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:13:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 05:04:24 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	write_arguments();

static void	write_acb(t_op options, int fd, char *str, int *cursor)
{
	int				i;
	unsigned char	acb;

	i = -1;
	acb = 0;
	while (++i < options.count_args)
	{
		if (str[0] == REG_CHAR)
			acb += (REG_CODE << ((3 - i) * 2));
		else if (str[0] == '%')
			acb += (DIR_CODE << ((3 - i) * 2));
		else
			acb += (IND_CODE << ((3 - i) * 2));
		str = ft_strchr(str, SEPARATOR_CHAR)
			? ft_strchr(str, SEPARATOR_CHAR) + 1 : str;
	}
	ft_putchar_fd(acb, fd);
	*cursor++;
}

int			writing_process(t_assembler *ass, t_writer *writer, char **buffer, int fd)
{
	if (ft_strchr(buffer[0], LABEL_CHAR))
		writer->token = 1;
	if (buffer[writer->token])
	{
		if (writer->command_index = define_index(ass->options, buffer[writer->token]))
		{
			ft_putchar_fd(writer->command_index, fd);
			writer->cursor++;
		}
		else
			return (0);
		writer->curr_command = writer->cursor;
		if (ass->options[writer->command_index].acb)
			write_acb(ass->options[writer->command_index], fd,
					buffer[writer->token + 1], &(writer->cursor));
	}
	//write_arguments();
	return (1);
}
