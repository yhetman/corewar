/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:07:40 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 14:18:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strlen_of_word(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !IS_SPACE(str[i]))
		i++;
	return (i);
}

int				ft_is_integer(const char *arg)
{
	long		tmp;
	size_t		len;

	len = ft_strlen_of_word(arg);
	if (len > 11)
		return (0);
	tmp = ft_atoi(arg);
	if ((long)INT_MAX < tmp
		|| tmp < (long)INT_MIN)
		return (0);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!IS_DIGIT(*arg))
		return (0);
	while (*arg && !IS_SPACE(*arg))
		if (!IS_DIGIT(*arg++))
			return (0);
	return (1);
}
