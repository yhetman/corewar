/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_all_token_details.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:12:25 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 18:47:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		store_all_token_details(t_assembler		*ass)
{
	int	i;

	i = -1;
	while (++i < 17)
		ass->options[i] = g_options[i];
	i = 1;
	while (ass->stored[++i] != NULL)
		if (ass->stored[i][0] && validate_token(ass->stored[i][0]))
			ass->count++;
	return (1);
}
