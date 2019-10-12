/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:59:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/12 04:56:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_commands(char **split)
{
	int		j;

	j = -1;
	if (DEBUG)
		printf("|great_freeing| -> |free_commands|\n");
	if (!split)
		return ;
	while (split[++j])
	{
		if (DEBUG)
			printf("|freed units counter|%s|-|%d|\n", split[j], j);
		free(split[j]);
	}	
	free(split);
}

static void	free_stored_info(char ***grid)
{
	int		i;
	int		j;

	i = -1;
	if (DEBUG)
		printf("|great_freeing| -> |free_stored_info|\n");
	if (grid)
	{
		while (grid[++i])
		{
			j = -1;
			while(grid[i][++j])
				printf("|%d|-|%d|--|%s|\n", i, j, grid[i][j]);
		}
		i = -1;
		while (grid[++i])
		{
			j = -1;
			if (i < 2)		
			{
				printf("|free grid |%s|-|%d|\n", grid[i][0], i);
				free(grid[i][0]);
			}
			while (i > 1 && grid[i][++j])
			{
				printf("|free grid |%s|-|%d|-|%d|\n", grid[i][j], i, j);
				free(grid[i][j]);
			}
			free(grid[i]);
			printf("|counter of cycle|--|%d|\n", i);
		}
		free(grid);
	}
}

static void	free_tokens_name(t_token *tokens, int count)
{
	int		j;

	j = -1;
	if (DEBUG)
		printf("|great_freeing| -> |free_tokens_name|\n");
	if (!tokens)
		return ;
	while (++j < count)
		free(tokens[j].name);
	free(tokens);
}

int			great_freeing(t_assembler *ass, char *line)
{
	
	if (DEBUG)
		printf("|great_freeing|\n");
	free_commands(ass->command);
	free_stored_info(ass->stored);
	free_tokens_name(ass->tokens, ass->count);
	ft_strdel(&line);
	return (0);
}
