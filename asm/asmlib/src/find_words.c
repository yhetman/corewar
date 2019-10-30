/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:46:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 22:31:42 by botkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

static char	*skip_word(char *str)
{
	while (*str && (!IS_TABUL(*str)))
	{
		if (*str == SEPARATOR_CHAR)
		{
			str++;
			while (*str && IS_TABUL(*str))
				++str;
		}
		str++;
	}
	return (str);
}

int			find_words(char *str)
{
	char	*tmp;
	int		words;

	words = 0;
	tmp = str;
	while (*tmp)
	{
		while (IS_TABUL(*tmp))
			++tmp;
		if (*tmp == ',')
			while (IS_TABUL(*tmp))
				++tmp;
		else if (*tmp == COMMENT_CHAR)
			tmp = skip_word(tmp);
		else if (++words)
			tmp = skip_word(tmp);
	}
	return (words);
}
