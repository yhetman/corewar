/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:52:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/07 18:52:30 by yhetman          ###   ########.fr       */
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

t_op		g_options[17];
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
void		ft_strdel(char **as);
char		*ft_strnew(size_t size);
char		*ft_strchr(const char *str, int c);
#endif
