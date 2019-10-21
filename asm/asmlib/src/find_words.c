/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:46:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/21 21:42:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

static char	*skip_word(char *str)
{
	while (*str && !IS_TABUL(*str))
		++str;
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
		if (*tmp == COMMENT_CHAR)
			tmp = skip_word(tmp);
		else if (++words)
			tmp = skip_word(tmp);
	}
	return (words);
}
