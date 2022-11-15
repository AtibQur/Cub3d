/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 16:21:12 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/11/17 12:33:40 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# define MAX_FD 1024

int		find_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strcorrect(char *str);
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
char	*get_next_line(int fd);

#endif
