/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_byte_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:24:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/26 17:26:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool	check_magic_bytes(int fd)
{
	long	result;
	char	*buff;
	t_byte	sig_byte;

	if ((result = read(fd, &buff, 4)) < 0
				|| result < 4)
		return (0);
	sig_byte = (t_byte)(buff[0] & 0x80);

}

int	check_byte_code(t_champion	*champ, int fd)
{
	if (!check_magic_bytes(fd))
		return (0);
	if (!check_header(champ->head, fd))
		return (0);
	if (!check_null(fd))
		return (0);
	if (!check_exec_code_size(fd))
		return (0);
}
