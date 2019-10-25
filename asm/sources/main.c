/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:06:55 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/24 00:07:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static inline void	print_usage(void)
{
	ft_putstr_fd("Usage: ./asm {champion.s}\n", STD_OUT);
	ft_putstr_fd("\t{champion.s}   — from assemble to bytecode\n", STD_OUT);
}

static inline void	print_requirements_to_files(char *file)
{
	ft_putstr_fd("File ", STD_OUT);
	ft_putstr_fd(file, STD_OUT);
	ft_putstr_fd("must have an extension .s and do not be blanked!\n", STD_OUT);
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
		print_usage();
	while (i < argc)
	{
		ft_putstr_fd("Processing file ", STD_OUT);
		ft_putstr_fd(argv[i], STD_OUT);
		ft_putchar_fd('\n', STD_OUT);
		if (!check_format(argv[i]))
		{
			print_requirements_to_files(argv[i]);
			i++;
		}
		else
			go_to_assembler(argv[i]);
		i++;
	}
	return (0);
}
