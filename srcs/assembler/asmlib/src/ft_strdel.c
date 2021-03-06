/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:00:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/23 09:27:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

int		ft_strdel(char **as)
{
	if (as == NULL)
		return (0);
	free(*as);
	*as = NULL;
	return (0);
}
