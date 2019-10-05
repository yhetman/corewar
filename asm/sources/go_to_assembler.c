/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_assembler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:38:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/05 23:58:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	count_lines_and_signs(char *content, int *signs, int *lines)
{
	while (content++)
	{
		if (*content == '\n')
			(*lines)++;
		(*signs)++;
	}
}

static int	reading_process(char *file, t_reader *reader)
{
	char	buffer[BUFF_SIZE + 1];
	int		content;
	int		fd;

	ft_bzero(buffer, BUFF_SIZE + 1);
	ft_bzero(reader, sizeof(t_reader*));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((content = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[content] = '\0';
		count_lines_and_signs(buffer, &reader->sign, &reader->line);
	}
	if (content  > -1)
		lseek(fd, 0, SEEK_SET);
	if (!reader->sign|| reader->line < 4)
		return (-1);
	return (fd);
}

static inline  int	error_exit(char *line, char *err_msg)
{
	ft_strdel(&line);
	ft_putstr_fd(err_msg, STD_ERR);
	return (0);
}
	_	
static int	set_reader(char *file, t_assembler *ass, t_reader *reader, char *line)
{
	int				fd;

	if ((fd = reading_process(file, reader)) < 0)
		return (error_exit(line, "ERROR OCCURED!"));
	if (!reader->line || !reader->sign)
		return (error_exit(line, "ERROR OCCURED: file is empty"));
	if (!(line = ft_strnew((reader->sign) + 1)))
		return (error_exit(line, "ERROR OCCURED!");
	if (read(fd, line, reader->sign) < 0)
		return (error_exit(line, "ERROR OCCURED: reading failed"));
	line[reder->sign] = '\0';
	if (close(fd) < 0)
		return (error_exit(line, "ERROR OCCURED: closing of fd failed"));
	if (!great_initialization(ass, reader->line, line))
		return (great_freeing(ass, line));
	return (1);
}

int					go_to_assembler(char *file)
{
//	t_header		header;
	t_assembler		ass;
	t_reader		reader;

	ft_bzero(&ass, sizeof(t_assembler*));
	if (!set_reader(file, &ass, &reader, NULL))
		return (0);
	return (0);
}
