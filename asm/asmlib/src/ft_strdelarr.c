/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:10:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/23 09:19:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asmlib.h"

int			ft_strdelarr(char ***as)
{
	char	**tmp;

	if (!as || !*as)
		return (0);
	tmp = *as;
	while (*tmp && !(ft_strdel(&(*tmp))))
		++tmp;
	free(*as);
	*as = NULL;
	return (0);
}
