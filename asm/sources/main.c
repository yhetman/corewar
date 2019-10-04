/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:06:55 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/04 19:36:02 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static inline void			print_usage(void)
{
	ft_putstr("Usage: ./asm {champion.s}\n");
	ft_putstr("\tchampion.s   — from assemble to bytecode\n");
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

int					reader(char *file, t_reader *reader)
{		
	if (file && reader)
	{}
	return (0);
}

int					set_reader(char *file, t_assembler *ass, t_reader *r, char *line)
{
	int				fd;

	ass->command = NULL;
	ass->stored = NULL;
	if ((fd = reader(file, r)) < 0)
		return (0);
	if (ass)
		return (1);
	//	return (reading_error());
	if (!(line = ft_strnew((r->sign) + 1)))
		return (0);
	return (0);
}

int					go_to_assembler(char *file)
{
	char			*line;
	t_header		header;
	t_assembler		ass;
	t_reader		reader;

	if (!set_reader(file, &ass, &reader, file))
		return (0);
	return (0);
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
