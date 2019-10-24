/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:29:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 15:21:26 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	find_number_of_token(t_token *tokens, int amount, int numb)
{
	int	i;

	i = -1;
	while (++i < amount)
		if (tokens[i].count == numb)
				return (i);
	return (i);
}

static int	no_command(t_assembler *ass, int *i, int *count, int *current)
{   
        int	token;

	token = 0;
	if (ass->stored[*i][0] && ass->stored[*i][0][0] &&
		ass->stored[*i][0][0] == COMMENT_CHAR)
		;
	else if (!ass->stored[*i][0] || !ass->stored[*i][0][0])
		token = 0;
	else if (ass->stored[*i][0] &&
		ft_strchr(ass->stored[*i][0], LABEL_CHAR))
	{
		token = 1;
		*current = find_number_of_token(ass->tokens, ass->count, *i);
		if (*current > -1)
			ass->tokens[*current].byte.first = *count;
	}
	return (token);
}

static bool	find_command(t_assembler *ass, int *i, int *count, int token)
{
    int		j;
	int		index;
	int		args;

	if (!(index = define_index(ass->options, ass->stored[*i][token])))
		return (false);
	if (ass->options[index].args_bc)
		(*count)++;
	j = 0;
	args = -1;
	while (++args < ass->options[index].count_args)
	{
		if (ass->stored[*i][1 + token][j] == REG_CHAR)
			(*count)++;
		else if (ass->stored[*i][1 + token][j] == '%')
			*count = ass->options[index].command_size
			? *count + 2
                        : *count + 4;
		else
			*count += 2;
		while (ass->stored[*i][1 + token][j] &&
			ass->stored[*i][1 + token][j] != SEPARATOR_CHAR)
			j++;
		j++;
	}
	return (true);
}

int		catch_tokens(t_assembler *ass)
{
	int	count;
	int	i;
	int	current;
	int	token;

	count = 0;
	i = 1;
	current = -1;
	while (ass->stored[++i])
	{
		token = no_command(ass, &i, &count, &current);
		if (ass->stored[i][token] && ass->stored[i][token][0]
				&& ass->stored[i][token][0] != COMMENT_CHAR)
		{
			count++;
			if (!find_command(ass, &i, &count, token))
				return (0);
		}
	}
	return (count);
}
