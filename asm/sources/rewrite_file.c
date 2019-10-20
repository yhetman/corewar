/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:56:13 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/20 19:28:16 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
//	puthexa_fd(bytes, fd);
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

static int	catch_tokens(t_assembler *ass)
{
	int	count;
	int	i;
	int	current_token;
	int	is_token;

	count = 0;
	i = 1;
	current_token = -1;
	while (ass->stored[++i])
	{
		is_token = no_command(ass, &i, &count, &current_token);
		if (ass->stored[i][is_token] && ass->stored[i][is_token][0]
				&& ass->stored[i][is_token][0] != COMMENT_CHAR)
		{
			count++;
			if (!find_command(ass, &i, &count, is_token))
				return (0);
		}
	}
	return (count);
}

int	rewrite_file(t_assembler ass, t_header head, int lines,  char *file)
{
	int	fd;
	int	i;

	if ((fd = change_extension(file)) < 0)
		return (0);
	if (!write_header(fd, head.prog_name, COREWAR_EXEC_MAGIC, 0))
		return (0);
//	if (!(i = catch_tokens(&ass)) || i > CHAMP_MAX_SIZE)
//		return (0);
//	if (write_comment(fd, head.comment, i, 4) == 0)
//		return (0);
//	if (write_tokens(ass, fd, lines) == 0)
//		return (0);
	if (close(fd) < 0)
		return (0);
	return (1);
}
