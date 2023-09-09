/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:56:03 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/01 10:47:23 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

/**
 * Searches for the biggest value in the stack and returns the index of it
 */
int	find_max(t_stack *stack)
{
	int	max_index;
	int	index;

	index = stack->length - stack->holds;
	max_index = index;
	while (index < stack->length)
	{
		if (stack->data[index] > stack->data[max_index])
			max_index = index;
		index++;
	}
	return (max_index);
}

int	find_smallest(t_stack *stack)
{
	int	index;
	int	smalles_id;

	index = stack->length - stack->holds;
	smalles_id = index;
	while (index < stack->length)
	{
		if (stack->data[index] < stack->data[smalles_id])
			smalles_id = index;
		index++;
	}
	return (smalles_id);
}

int	fns(t_stack *stack, int reference)
{
	int	index;
	int	small_id;

	index = stack->length - stack->holds;
	small_id = find_smallest(stack);
	if (stack->data[small_id] > 0)
		small_id = 0;
	while (index < stack->length)
	{
		if (stack->data[index] > stack->data[small_id]
			&& stack->data[index] < reference)
			small_id = index;
		index++;
	}
	if (small_id == 0 && stack->length - stack->holds != 0)
		return (find_max(stack));
	return (small_id);
}

int	fnb(t_stack *stack, int reference)
{
	int	index;
	int	big_id;

	index = stack->length - stack->holds;
	big_id = find_max(stack);
	while (index < stack->length)
	{
		if (stack->data[index] < stack->data[big_id]
			&& stack->data[index] > reference)
			big_id = index;
		index++;
	}
	if (big_id == 0 && stack->length - stack->holds != 0)
		return (find_max(stack));
	return (big_id);
}
