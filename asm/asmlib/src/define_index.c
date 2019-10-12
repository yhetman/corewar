/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:08:46 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/12 03:08:58 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

int		define_index(t_op *options, char *command)
{
	int	index;

	index = 0;
	while (index < 17)
	{
		if (!ft_strcmp(command, options[index].name))
			return (options[index].index);
				index++;
	}
	return (0);
}
