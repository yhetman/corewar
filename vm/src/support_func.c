/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:20:18 by user              #+#    #+#             */
/*   Updated: 2019/09/25 21:57:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/corewar_error_manager.h"

int						calc_pos(int pos)
{
	pos %= MEM_SIZE;
	if (pos < 0)
		pos += MEM_SIZE;
	return (pos);
}

int						ft_read_data(const int fd, void *buf, const int nb)
{
	int			ret;

	ret = read(fd, buf, nb);
	if (ret < 0)
		ft_abort("");
	return (ret);
}

unsigned int			ft_read_bnum(const int fd, const int cnum)
{
	int					i;
	unsigned int		res;
	unsigned char		buf[cnum];

	i = 0;
	res = 0;
	ft_bzero(&buf, cnum);
	ft_read_data(fd, buf, cnum);
	while (i < cnum)
	{
		res <<= 8;
		res |= buf[i++];
	}
	return (res);
}

int						ft_read_num(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		if (!ft_isdigit(src[i]))
			ft_abort(ERR_INV_PAR);
	i = ft_atoi(src);
	return (i);
}

void					ft_fill_map(t_cw *cw, int pl_num)
{
	int				step;
	int				i;
	unsigned char	*tmp_map;

	tmp_map = cw->map;
	step = MEM_SIZE / pl_num;
	i = -1;
	while (++i < pl_num)
	{
		ft_memcpy(tmp_map, PL(i).code, PL(i).code_size);
		tmp_map += step * sizeof(char);
	}
	cw->last_player = &PL(cw->num_players - 1);
}
