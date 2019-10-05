/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:06:55 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/06 00:03:05 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static inline void	print_usage(void)
{
	ft_putstr_fd("Usage: ./asm {champion.s}\n", STR_OUT);
	ft_putstr_fd("\t{champion.s}   — from assemble to bytecode\n", STD_OUT);
}

static inline void	print_requirements_to_files(char *file)
{
	ft_printf("File %s must have an extension .s and do not be blanked!\n", file);
}

static inline bool	check_format(char *file)
{
	if (ft_strlen(file) < 3 || file[ft_strlen(file) - 1] != 's'
			|| file[ft_strlen(file) - 2] != '.')
		return (false);
	else
		return (true);
}

int					main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		print_usage();	// print usage
	while (i < argc)
	{
		ft_printf("Processing file %s\n", argv[i]);
		if (!check_format(argv[i]))
		{
			print_requirements_to_files(argv[i]);
			i++;
		}
		else
			go_to_assembler(argv[i]);		//	assembler itself
		i++;
	}
	return (0);
}
