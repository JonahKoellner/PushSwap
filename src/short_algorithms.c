/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:58:38 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/30 10:26:28 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

// operations combinations for norminette to be quiet in case_algorithm
void	s_rr(t_stack *stack)
{
	s(stack);
	rr(stack, 0);
}

void	s_r(t_stack *stack)
{
	s(stack);
	r(stack, 0);
}

// Case Algorithm for 3 items

void	case_algorithm(t_stack	*st, int l)
{
	if (st->data[l + 2] > st->data[l] && st->data[l + 2] > st->data[l + 1])
	{
		if (st->data[l + 1] > st->data[l])
			return ;
		else
			s(st);
		return ;
	}
	else if (st->data[l] > st->data[l + 1] && st->data[l] > st->data[l + 2])
	{
		if (st->data[l + 1] > st->data[l + 2])
			s_rr(st);
		else
			r(st, 0);
		return ;
	}
	else if (st->data[l + 1] > st->data[l] && st->data[l + 1] > st->data[l + 2])
	{
		if (st->data[l + 2] > st->data[l])
			s_r(st);
		else
			rr(st, 0);
		return ;
	}
}

// extra_case_algorithm
/**
 * For length 4 and 5 where they can use the case_algorithm with extra steps
*/
// void	extra_case_algorithm(t_stack *s_a, t_stack *s_b)
// {
// 	int	way;
// 	int	length;
// 	int	snap;

// 	while (s_a->holds > 3)
// 		p(s_a, s_b, 1);
// 	case_algorithm(s_a, s_a->length - s_a->holds);
// 	while (s_b->holds)
// 	{
// 		// way = shortest_path(s_b->data[s_b->length - s_b->holds], s_a);
// 		// length = path_length(s_b->data[s_b->length - s_b->holds], s_a);
// 		// printf("fdf%d way:%d\n", length, way);
// 		snap = 0;
// 		while (snap++ < length)
// 		{
// 			if (way)
// 				rr(s_a, 0);
// 			else
// 				r(s_a, 0);
// 		}
// 		p(s_a, s_b, 0);
// 		while (snap--)
// 		{
// 			if (way)
// 				rr(s_a, 0);
// 			else
// 				r(s_a, 0);
// 		}
// 	}
// 	// printf("%d\n",shortest_path(s_b->data[s_b->length - s_b->holds], s_a));
// }
