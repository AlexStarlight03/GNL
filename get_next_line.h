/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:49:56 by adube             #+#    #+#             */
/*   Updated: 2023/05/31 14:12:51 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*str_join(char const *s1, char const *s2);
char	*string_search(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif