/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_byte_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:24:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 12:47:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_code	*read_exec_code(t_header *head, int fd)
{
	t_read		result;
	t_byte		*buff;
	t_byte		byte;

	if (!(buff = (t_byte*)malloc(head->prog_size)))
		return (NULL);
	if ((result = read(fd, buff, head->prog_size)) == -1
			|| result < head->prog_size
			|| read(fd, &byte, 1))
		return(NULL);
	return(buff);
}

static long	read_bytes_convert_to_long(int fd, int bytes, long result)
{
	t_read	read;
	t_byte	buff[bytes];
	t_byte	sig_byte;
	int		i;

	i = 0;
	if ((read = read(fd, &buff, bytes)) < 0
				|| read < bytes)
		return (0);
	sig_byte = (t_byte)(buff[0] & 0x80);
	while (bytes--)
		result += ((sig_byte) ? ((buff[bytes - 1] ^ 0xFF) << (i++ * 8))
				: (buff[bytes - 1] << (i++ * 8)));
	return ((sig_byte) ? result : (~result));
}

static char	*read_bytes_convert_to_str(int fd, unsigned int length)
{
	t_read	res;
	t_byte	*buff;
	t_byte	byte;

	if (!(buff = (t_byte*)malloc(length *sizeof(t_byte))))
		return (NULL);
	if ((res = read(fd, buff, length)) == -1 
			|| res < len || (read(fd, &byte, 1) != 0))
		return (NULL);
	return (buff);
}

static int	check_header_bytecode(t_header *head, int fd)
{
	if (!(head->prog_name = read_bytes_convert_to_str(fd, PROG_NAME_LENGTH)))
		return (0);
	if (read_bytes_convert_to_long(fd, 4, 0))
		return (0);
	if ((head->prog_size = read_bytes_convert_to_long(fd, 4, 0)) < 0
			|| head->prog_size > CHAMP_MAX_SIZE)
		return (0);
	if (!(head->comment = read_bytes_convert_to_str(fd, COMMENT_LENGTH)))
		return (0);
	if (read_bytes_convert_to_long(fd, 4, 0))
		return (0);
	return (1);
}

int			check_byte_code(t_champion	*champ, int fd)
{
	long	value;

	value = read_bytes_convert_to_long(fd, 4);
	if (value != COREWAR_EXEC_MAGIC)
		return (0);
	if (!check_header_bytecode(champ->head, fd))
		return (0);
	champ->code = read_exec_code(champ->head, fd);
	return (1);
}
