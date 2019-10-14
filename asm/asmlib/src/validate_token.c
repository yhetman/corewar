/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:32:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/14 22:56:37 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

bool	validate_token(char *line)
{
	int	i;

	i = 0;
	if (!(ft_strchr(LABEL_CHARS, line[0])) || !(ft_strchr(line, ':')))
		return (false);
	printf("|checking |%s|\n", line);
	while (line[i] != ':')
	{
		if (!(ft_strchr(LABEL_CHARS, line[i])))
			return (false);
		i++;
	}
	return (true);
}
