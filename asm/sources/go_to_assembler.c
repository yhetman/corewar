/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_assembler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:38:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/12 15:57:11 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

static void			counts_char_line(char *buff, t_reader *reader)
{
	int	i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			reader->line += 1;
	reader->sign += i;
}


static int			reading_process(char *file, t_reader *reader)
{
	char			buffer[BUFF_SIZE + 1];
	int				content;
	int				fd;

	if (DEBUG)
		printf("|set_reader| -> |reading_process|\n");
	buffer[0] = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	if (DEBUG)
		printf("| File opened succesfully! |");
	while ((content = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[content] = '\0';
		counts_char_line(buffer, reader);
	}
	if (DEBUG)
		printf("|File consists of |%d| signs and |%d| lines|\n", reader->sign, reader->line);
	if (content > -1)
		lseek(fd, 0, SEEK_SET);
	if (!reader->sign || reader->line < 4)
		return (-1);
	return (fd);
}

static inline int	error_exit(char *line, char *err_msg)
{
	ft_strdel(&line);
	ft_putstr_fd(err_msg, STD_ERR);
	return (0);
}

static int			set_reader(char *file, t_assembler *ass,
						t_reader *reader, char *line)
{
	int				fd;

	if (DEBUG)
		printf("|go_to_assembler| -> |set_reader|\n");
	if ((fd = reading_process(file, reader)) < 0)
		return (error_exit(line, "ERROR OCCURED: reading process failed\n"));
	if (!reader->line || !reader->sign)
		return (error_exit(line, "ERROR OCCURED: file is empty\n"));
	if (!(line = ft_strnew(reader->sign + 1)))
		return (error_exit(line, "ERROR OCCURED: malloc failed\n"));
	if (read(fd, line, reader->sign) < 0)
		return (error_exit(line, "ERROR OCCURED: reading failed\n"));
	line[reader->sign] = '\0';
	if (close(fd) < 0)
		return (error_exit(line, "ERROR OCCURED: closing of fd failed\n"));
	if (!great_initialization(ass, reader->line, line))
		return (great_freeing(ass, line));
	return (1);
}

int					go_to_assembler(char *file)
{
	t_header		header;
	t_assembler		ass;
	t_reader		reader;

	ft_bzero(&reader, sizeof(t_reader));
	ft_bzero(&ass, sizeof(t_assembler));
	ft_bzero(&ass.tokens, sizeof(t_token));
	if (!set_reader(file, &ass, &reader, NULL))
		return (0);
	store_all_token_details(&ass);
	if (!file_checker(&ass, &header))
		return (great_freeing(&ass, NULL));
	return (1);
}
