/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_assembler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:38:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/23 10:59:06 by blukasho         ###   ########.fr       */
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

	buffer[0] = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((content = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[content] = '\0';
		counts_char_line(buffer, reader);
	}
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
	if (!great_initialization(ass, reader->line, line) && ft_strdel(&line))
		return (0);
	if (line)
		ft_strdel(&line);
	return (1);
}

int					go_to_assembler(char *file)
{
	t_assembler		*ass;
	t_header		*header;
	t_reader		*reader;

	ass = init_t_assembler();
	reader = init_t_reader();
	if (!set_reader(file, ass, reader, NULL))
		return (clear_t_assembler(ass) + clear_t_reader(reader));
	store_all_token_details(ass);
	header = init_t_header();
	if (!file_checker(ass, header)) //file_checker() return 0
	{
		printf("FUCK\n");
		print_t_assembler(ass);//print
		clear_t_assembler(ass);
		clear_t_reader(reader);
		clear_t_header(header);
		return (0);
	}
//	rewrite_file(ass, header, reader->line, file);
	clear_t_assembler(ass);
	clear_t_reader(reader);
	clear_t_header(header);
	return (1);
}
