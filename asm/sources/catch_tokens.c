/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:29:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/20 19:37:15 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	find_command(t_assembler *ass, int *i, int *count, int is_token);

static int	no_command(t_assembler *ass, int *i, int *count, int *current);

int		catch_tokens(t_assembler *ass)
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
