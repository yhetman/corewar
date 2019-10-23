/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:31:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/23 10:52:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	print_char_arr(char **arr)
{
	if (arr)
		while (*arr)
			printf("|%s|\n", *(arr++));
}

void		print_t_assembler(t_assembler *ass)
{
	char	**command;
	char	***stored;
	int		i;

	if (!ass)
		return ;
//	printf("<<<<<<ass->command>>>>>\n");
//	if (ass->command)
//		print_char_arr(ass->command);
//	printf("<<<<<<ass->command>>>>>\n\n");
//	printf("<<<<<<ass->stored>>>>>\n");
//	if (ass->stored && (stored = ass->stored))
//	{
//		while (*stored)
//		{
//			printf(">\n");
//			print_char_arr(*(stored++));
//		}
//	}
//	printf("<<<<<<ass->stored>>>>>\n\n");
	i = 0;
	printf("<<<<<<ass->tokens>>>>>\n");
	while (ass->tokens && i < ass->count)
		printf("|%s|\n", ass->tokens[i++].name);
	printf("<<<<<<ass->tokens>>>>>\n\n");
}
