/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:38:11 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/23 10:22:25 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		clear_t_header(t_header *header)
{
	if (!header)
		return (0);
	free(header);
	return (0);
}

int		clear_t_reader(t_reader *reader)
{
	if (!reader)
		return (0);
	free(reader);
	return (0);
}

int		clear_t_assembler(t_assembler *ass)
{
	int	i;

	if (!ass)
		return (0);
	if (ass->command)
		ft_strdelarr(&(ass->command));
	if (ass->stored)
	{
		i = 0;
		while (ass->stored[i])
			ft_strdelarr(&(ass->stored[i++]));
		free(ass->stored);
	}
	i = 0;
	while (ass->tokens && i < ass->count && !ft_strdel(&(ass->tokens[i].name)))
		++i;
	if (ass->tokens)
		free(ass->tokens);
	if (ass->options)
		free(ass->options);
	free(ass);
	return (0);
}
