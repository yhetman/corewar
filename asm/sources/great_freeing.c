/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:59:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 16:40:29 by botkache         ###   ########.fr       */
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
	{
		free(split[j]);
	}
	free(split);
}

static void	fuck(char **arr)
{
	char	**you;

	you = arr;
	while (*you)
		ft_strdel(&*(you++));
	free(arr);
}

static void	free_stored_info(char ***grid)
{
	char	***tmp;

	tmp = grid;
	while (*grid)
		fuck(*(grid++));
	free(tmp);
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
