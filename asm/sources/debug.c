/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:31:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/21 22:12:58 by blukasho         ###   ########.fr       */
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
}
