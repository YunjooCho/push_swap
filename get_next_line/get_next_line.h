/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:01:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 22:33:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_ginfo
{
	char		buffer[BUFFER_SIZE];
	int			index;
	int			rbyte;
	int			len;
	int			total;
}	t_ginfo;

char	*get_next_line(int fd);
void	ft_gnl_memcpy(char *dst, char *src, size_t len);
char	*join(char *old, t_ginfo *node);
void	ft_init(t_ginfo *node, char **result);
char	*ft_exception(t_ginfo *node, char *result);

#endif
