/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:46:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 14:57:10 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

int	find_words(char *str)
{
	char	*tmp;
	int		words;

	words = 0;
	tmp = str;
	while (tmp && *tmp)
	{
		if (IS_TABUL(*tmp))
			tmp++;
		else if (*tmp == COMMENT_CHAR)
		{
			words++;
			break ;
		}
		else if (tmp == str || IS_TABUL(*tmp - 1))
		{
			words++;
			tmp++;
		}
		else
			tmp++;
	}
	return (words);
}
