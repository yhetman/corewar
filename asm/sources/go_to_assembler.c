/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_assembler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:38:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/04 21:07:38 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	count_lines_and_signs(char *content, int signs, int lines)
{
	while (content++)
	{
		if (*content == '\n')
			lines++;
		signs++;
	}
}

static int	reading_process(char *file, t_reader *reader)
{
	char	buffer[BUFF_SIZE + 1];
	int		content;
	int		fd;

	ft_bzero((void*)buffer, sizeof(char[2]));
	ft_bzero((void*)reader, sizeof(t_reader*));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((content = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[content] = '\0';
		count_lines_and_signs(buffer, reader->sign, reader->line);
	}
	if (content  > -1)
		lseek(fd, 0, SEEK_SET);
	if (!reader->sign|| reader->line < 4)
		return (-1);
	return (fd);
}

int					set_reader(char *file, t_assembler *ass, t_reader *reader, char *line)
{
	int				fd;

	ass->command = NULL;
	ass->stored = NULL;
	if ((fd = reading_process(file, reader)) < 0)
		return (0);
	if (!reader->line || !reader->sign)
		return (ft_putstr_fd("ERROR OCCURED: file is empty", STD_ERR));
	if (!(line = ft_strnew((reader->sign) + 1)))
		return (0);
	return (0);
}

int					go_to_assembler(char *file)
{
	char			*line;
	t_header		header;
	t_assembler		ass;
	t_reader		reader;

	if (!set_reader(file, &ass, &reader, file))
		return (0);
	return (0);
}
