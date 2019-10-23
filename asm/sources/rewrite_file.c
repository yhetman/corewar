/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:56:13 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/23 23:35:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int write_commands(t_assembler *ass, int fd, int lines)
{
	int		i;
	int		res;
	char	**buffer;

	i = 1;
	res = 0;
	while (++i < lines)
	{
		buffer = ass->stored[i];
		printf("|%d|-|OK!|\n", i);
		if (!buffer || !buffer[0] || !buffer[0][0]
				|| buffer[0][0] == COMMENT_CHAR)
			continue ;
		else if (ft_strchr(buffer[0], LABEL_CHAR))
			res = 0;// init_writer(ass, buffer, fd);
	}
	return (res);
}

static bool write_header(int fd, char *destin, int bytes, int plus)
{
	int		i;
	int		amount;
	long	length;

	amount = 0;
	length = bytes;;
	while (length)
	{
		length /= 256;
		amount++;
	}
	while (4 - amount + plus)
	{
		ft_putchar_fd(0x0, fd);
		amount++;
	}
//	ft_puthex_fd(bytes, fd);
	i = -1;
	while (destin[++i])
		ft_putchar_fd(destin[i], fd);
	while (++i < sizeof(destin) + plus)
		ft_putchar_fd(0x0, fd);
	return (true);
}

static int	change_extension(char	*file)
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

int	rewrite_file(t_assembler *ass, t_header *head, int lines,  char *file)
{
	int	fd;
	int	i;

	if ((fd = change_extension(file)) < 0)
		return (0);
	if (!write_header(fd, head->prog_name, COREWAR_EXEC_MAGIC, 0))
		return (0);
	if (!(i = catch_tokens(ass)) || i > CHAMP_MAX_SIZE)
		return (0);
	if (!write_header(fd, head->comment, i, 4))
		return (0);
	if (!write_commands(ass, fd, lines))
		return (0);
	if (close(fd) < 0)
		return (0);
	return (1);
}
