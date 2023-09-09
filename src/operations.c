/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:23 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/01 09:57:56 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"
#include <stddef.h>

// /**
//  * Get top of stack
// */

/**
 * Operation sa/sb:
 * Swap the first 2 elements at the top of stack a.
 * 	Do nothing if there is only one or no elements.
*/
int	s(t_stack *stack)
{
	int	temp;
	int	index;

	ft_printf("s%c\n", stack->id);
	if (stack->holds > 1)
	{
		index = stack->length - stack->holds;
		temp = stack->data[index];
		stack->data[index] = stack->data[index + 1];
		stack->data[index + 1] = temp;
	}
	return (0);
}

/**
 * Operation pa / pb:
 * Take the first element at the top of b and put it at the top of a.
 * swap == 0 -> push from b to a
 * swap == 1 -> push form a to b
*/
int	p(t_stack *a, t_stack *b, int swap)
{
	if (swap == 0)
	{
		ft_printf("p%c\n", a->id);
		if (b->holds)
		{
			a->data[a->length - a->holds - 1] = b->data[b->length - b->holds];
			b->data[b->length - b->holds] = 0;
			b->holds -= 1;
			a->holds += 1;
		}
	}
	if (swap == 1)
	{
		ft_printf("p%c\n", b->id);
		if (a->holds)
		{
			b->data[b->length - b->holds - 1] = a->data[a->length - a->holds];
			a->data[a->length - a->holds] = 0;
			b->holds += 1;
			a->holds -= 1;
		}
	}
	return (0);
}

/**
 * Operation rra / rrb:
 *  Shift down all elements of stack by 1
 * The last element becomes the first one
*/
int	rr(t_stack *stack, int combine)
{
	int	index;
	int	temp;

	if (!combine)
	{
		write(1, "rr", 2);
		write(1, &stack->id, 1);
		write(1, "\n", 1);
	}
	if (stack->holds == 0)
		return (-1);
	temp = stack->data[stack->length - 1];
	index = stack->length - 1;
	while (index > stack->length - stack->holds)
	{
		stack->data[index] = stack->data[index - 1];
		index--;
	}
	stack->data[stack->length - stack->holds] = temp;
	return (0);
}

/**
 * Operation ra / rb:
 *  Shift up all elements of stack by 1. The first element becomes the last one.
*/
int	r(t_stack *stack, int combine)
{
	int	index;
	int	temp;

	if (!combine)
		ft_printf("r%c\n", stack->id);
	if (stack->holds == 0)
		return (-1);
	temp = stack->data[stack->length - stack->holds];
	index = stack->length - stack->holds;
	while (index < stack->length - 1)
	{
		stack->data[index] = stack->data[index + 1];
		index++;
	}
	stack->data[stack->length - 1] = temp;
	return (0);
}
