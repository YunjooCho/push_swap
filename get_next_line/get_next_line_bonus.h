/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:01:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 22:40:19 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_ginfo
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	int				index;
	int				rbyte;
	int				len;
	int				total;
	struct s_ginfo	*next;
}	t_ginfo;

char	*get_next_line(int fd);
void	ft_memcpy_gnl(char *dst, char *src, size_t len);
char	*join(char *old, t_ginfo *node);
void	ft_init(t_ginfo *node, char **result);
char	*ft_exception(t_ginfo *node, char *result, t_ginfo **head);
t_ginfo	*ft_get_node(t_ginfo **head, int fd);
t_ginfo	*ft_lstadd_back(t_ginfo **head, int fd);
void	ft_remove_node(t_ginfo **head, int fd);

#endif
