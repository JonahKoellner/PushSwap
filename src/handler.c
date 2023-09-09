/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:56:44 by jkollner          #+#    #+#             */
/*   Updated: 2023/05/30 11:28:50 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

int	check_sorted(t_stack stack)
{
	int	index;
	int	check;

	index = stack.length - 1;
	while (index >= 0)
	{
		check = index;
		while (check >= 0)
		{
			if (stack.data[check] > stack.data[index])
				return (0);
			check--;
		}
		index--;
	}
	return (1);
}

void	decide_algo(t_stack *input_stack, t_stack *temp_stack)
{
	if (check_sorted(*input_stack))
		return ;
	else if (input_stack->length == 2)
	{
		if (input_stack->data[0] > input_stack->data[1])
			s(input_stack);
	}
	else if (input_stack->length == 3)
		case_algorithm(input_stack, input_stack->length - input_stack->holds);
	else
	{
		p(input_stack, temp_stack, 1);
		p(input_stack, temp_stack, 1);
		sort_stack(input_stack, temp_stack);
	}
}
