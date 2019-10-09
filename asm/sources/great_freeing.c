/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:59:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/09 20:51:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_commands(char **split)
{
	int		j;

	j = -1;
	if (!split)
		return ;
	while (split[++j])
		free(split[j]);
	free(split);
}

static void	free_stored_info(char ***grid)
{
	int		i;
	int		j;

	i = -1;
	if (!grid)
		return ;
	while (grid[++i])
	{
		if (i < 2)
			free(grid[i][0]);
		j = -1;
		while (i > 1 && grid[i][++j])
			free(grid[i][j]);
		free(grid[i]);
	}
	free(grid);
}

static void	free_tokens_name(t_token *tokens, int count)
{
	int		j;

	j = -1;
	if (!tokens)
		return ;
	while (++j < count)
		free(tokens[j].name);
	free(tokens);
}

int			great_freeing(t_assembler *ass, char *line)
{
	free_commands(ass->command);
	free_stored_info(ass->stored);
	free_tokens_name(ass->tokens, ass->count);
	ft_strdel(&line);
	return (0);
}
