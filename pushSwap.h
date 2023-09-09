/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/01 15:13:47 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include <stddef.h>

/**
 * Stack representation
 * 	- data (int *):
 * 		Holds the data in the stack
 * 	- length (int):
 * 		Stores the maximum length of the stack
 * 	- top (int):
 * 		Stores the current top element ontop of the stack
 * 		(already in index form (0-n))
 *	- id (char):
		Stores the id of the stack
		(here names a and b so a char is the id)
*/
typedef struct s_stack
{
	int		*data;
	int		length;
	int		holds;
	char	id;
}t_stack;

typedef struct s_instruct
{
	int		rot;
	void	(*op)(void*, void*);
}t_instruct;

int			s(t_stack *stack);
int			p(t_stack *a, t_stack *b, int swap);
int			r(t_stack *stack, int combine);
int			rr(t_stack *stack, int combine);
void		case_algorithm(t_stack	*stack, int l);
void		extra_case_algorithm(t_stack *s_a, t_stack *s_b);
void		decide_algo(t_stack *input_stack, t_stack *temp_stack);
int			sort_stack(t_stack *stack_a, t_stack *stack_b);
int			shortest_path(int s_val, t_stack *stack);
int			path_length(int s_val, t_stack *stack);
void		tr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
int			find_max(t_stack *stack);
int			find_smallest(t_stack *stack);
int			fns(t_stack *stack, int reference);
int			fnb(t_stack *stack, int reference);
long long	long_atoi(const char *str);

#endif
