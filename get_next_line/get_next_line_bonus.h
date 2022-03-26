/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:04:27 by seulah            #+#    #+#             */
/*   Updated: 2021/11/09 11:04:29 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*gnl_strdup(char *s1, char x, size_t start);
void		*gnl_calloc(size_t size);
size_t		gnl_strlen(const char *str, char x);
char		*ft_strrchr(const char *string, int symbol);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
