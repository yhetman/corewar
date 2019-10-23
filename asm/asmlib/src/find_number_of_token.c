/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number_of_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:59:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/23 18:01:15 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"
#include "../../includes/asm.h"

int	find_number_of_token(t_assembler *ass, int numb)
{
	int	i;

	i = -1;
	while (++i < ass->count)
		if (ass->tokens[i].count == numb)
			return (i);
	return (i);
}
