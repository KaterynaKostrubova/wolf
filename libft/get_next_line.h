/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:41:13 by kkostrub          #+#    #+#             */
/*   Updated: 2018/07/27 11:18:49 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 32
# define FD 4864
# define MEMALLOC(a) if(a){if (!(g.temp = newmemory()))return (-1);}
# define ERR(a) if(a){free(g.temp); g.temp = NULL; return(-1);}
# define RET_1(a) if(a){free(g.temp); g.temp = NULL; return(1);}
# define RET_SOLVE(a) if(a){free(v.temp_ptr); v.temp_ptr = NULL;  return(1);}
# define FREE_T(a) if(a){free(g.temp); g.temp = NULL;}

typedef struct	s_solve
{
	int			i;
	char		*temp_ptr;
	char		*ptr;
	int			end;
	char		*keep_temp;
}				t_solve;

typedef struct	s_gnl
{
	char		*temp;
	int			solve_value;
	int			rd;
}				t_gnl;

int				get_next_line(const int fd, char **line);
int				solve(char **keepf, char *temp, char **line);
char			*newmemory(void);

#endif
