/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:46 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/13 17:20:19 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999

# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_write_one_line(char *str);
char	*ft_reinit_stash(char *str);
size_t	ft_strlen_gnl(char *str);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_sub_or_join(char *stash, char *buffer);

#endif
