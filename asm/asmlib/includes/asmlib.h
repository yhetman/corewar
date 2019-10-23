/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:52:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/23 09:19:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASMLIB_H
# define ASMLIB_H

# include "op.h"
# include "macros.h"
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../includes/asm.h"

int	              find_number_of_token(t_assembler *ass, int numb);
int			define_index(t_op *options, char *command);
bool		validate_token(char *line);
int			find_words(char *str);
void		count_lines_and_signs(char *content, int *signs, int *lines);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(const char *s, int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(const char *s, int fd);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strsub(const char *str, unsigned int i, size_t len);
size_t		ft_strlen(const char *str);
int			ft_strdel(char **as);
int			ft_strdelarr(char ***as);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *str, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_atoi(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
#endif
