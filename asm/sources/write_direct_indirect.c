/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct_indirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:32:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 11:59:46 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	count_bytes(t_assembler *ass, t_writer *writer, char *line, int *hex);

static void	write_direct(t_assembler *ass, t_writer *writer,int *cur, char *line);

static void	write_indirect(t_assembler *ass, t_writer *writer, int *cur, char *line)
{
	int		hex;

	if (line[0] = LABEL_CHAR && !count_bytes(ass, writer, line, &hex))
		return ;
	else
		hex = ft_atoi(line) % 65536;
	hex = hex < 0 ? hex + 65536 : hex;
	ft_putchar_fd(hex / 256, writer->fd);
	ft_purchar_fd(hex % 256, writer->fd);
	(*cur)++;
}

void		write_direct_indirect(t_assembler *ass, t_writer *writer, char **buffer, int i)
{
	int		cur;
	char	*line;

	cur = &(writer->cursor);
	line = buffer[writer->token + 1] + i;
	if (buffer[writer->token +1][i] == '%')
		write_direct(ass, writer, &cur, line);
	else
		write_indirect(ass, writer, &cur, line);
}
