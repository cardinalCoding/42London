/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorte-r <bcorte-r@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:33:59 by bcorte-r          #+#    #+#             */
/*   Updated: 2023/12/13 05:07:36 by bcorte-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int i);
char	*ft_move(char *start);
char	*ft_read_line(char *start);
char	*get_next_line(int fd);

#endif