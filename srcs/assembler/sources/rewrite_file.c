/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:56:13 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 19:42:40 by botkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_writer	*init_writer(void)
{
	t_writer	*writer;

	writer = (t_writer *)malloc(sizeof(t_writer));
	ft_bzero(writer, sizeof(t_writer));
	return (writer);
}

static int		write_commands(t_assembler *ass, int fd, int lines)
{
	int			i;
	int			res;
	char		**buffer;
	t_writer	*writer;

	i = 1;
	res = 0;
	writer = init_writer();
	writer->fd = fd;
	writer->cursor = -1;
	while (++i < lines)
	{
		buffer = ass->stored[i];
		if (!buffer || !buffer[0] || !buffer[0][0]
				|| buffer[0][0] == COMMENT_CHAR)
			continue ;
		else
			res = writing_process(ass, writer, buffer, fd);
	}
	free(writer);
	return (res);
}

static int		change_extension(char *file)
{
	int		fd;
	int		i;
	char	*filename;

	i = -1;
	if (!(filename = ft_strnew(ft_strlen(file) + 3)))
		return (0);
	while (file[++i + 1])
		filename[i] = file[i];
	filename[i] = 'c';
	filename[i + 1] = 'o';
	filename[i + 2] = 'r';
	filename[i + 3] = '\0';
	if ((fd = open(filename, O_CREAT | O_RDWR, 0666)) < 0)
		return (fd);
	free(filename);
	return (fd);
}

static int		check(t_header *head)
{
	if (head->prog_name[0] == '\0')
		return (ft_putstr_fd("| NO NAME OF PLAYER |\n", STD_ERR));
	if (head->comment[0] == '\0')
		return (ft_putstr_fd("| NO COMMENT |\n", STD_ERR));
	return (0);
}

int				rewrite_file(t_assembler *ass, t_header *head,
				int lines, char *file)
{
	int	fd;
	int	i;

	if (check(head))
		return (0);
	if ((fd = change_extension(file)) < 0)
		return (0);
	ft_puthex_n_fd(COREWAR_EXEC_MAGIC, fd, 4);
	ft_putstr_fd(head->prog_name, fd);
	ft_puthex_n_fd(0x00, fd, (132 - ft_strlen(head->prog_name)));
	if (!(i = catch_tokens(ass)))
		return (0);
	ft_puthex_n_fd(i, fd, 4);
	ft_putstr_fd(head->comment, fd);
	ft_puthex_n_fd(0x00, fd, 2052 - ft_strlen(head->comment));
	if (!write_commands(ass, fd, lines))
		return (0);
	if (close(fd) < 0)
		return (0);
	ft_putstr_fd("| File successfully generated! |\n", STD_OUT);
	return (1);
}
