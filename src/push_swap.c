/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:32:40 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/01 10:14:25 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"
#include <unistd.h>

void	ft_free(t_stack *a, t_stack *b, int error)
{
	free(a->data);
	free(b->data);
	if (error)
		ft_putstr_fd("Error\n", 2);
}

int	check_num(char *num)
{
	int	index;

	index = 0;
	if (ft_strlen(num) == 0)
		return (1);
	if (long_atoi(num) > INT32_MAX || long_atoi(num) < INT32_MIN)
		return (1);
	if ((num[index] == '-' || num[index] == '+') && ft_strlen(num) > 1)
		index++;
	while (num[index])
	{
		if (!(num[index] >= '0' && num[index] <= '9'))
			return (1);
		index++;
	}
	return (0);
}

int	fill_data(t_stack *stack, char *argv[], int count)
{
	int	index;
	int	check;

	index = 0;
	while (index < count)
	{
		if (check_num(argv[index + 1]))
			return (1);
		stack->data[index] = ft_atoi(argv[index + 1]);
		check = index;
		while (check + 1 < count)
		{
			check++;
			if (stack->data[index] == ft_atoi(argv[check + 1]))
				return (1);
		}
		index++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	input_stack;
	t_stack	temp_stack;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (check_num(argv[1]))
			return (ft_putstr_fd("Error\n", 2), -1);
		else
			return (0);
	}
	input_stack.length = argc - 1;
	input_stack.data = ft_calloc(argc - 1, sizeof(int));
	input_stack.holds = argc - 1;
	input_stack.id = 'a';
	temp_stack.length = argc - 1;
	temp_stack.data = ft_calloc(argc - 1, sizeof(int));
	temp_stack.holds = 0;
	temp_stack.id = 'b';
	if (fill_data(&input_stack, argv, argc - 1))
		return (ft_free(&input_stack, &temp_stack, 1), 1);
	decide_algo(&input_stack, &temp_stack);
	ft_free(&input_stack, &temp_stack, 0);
	return (0);
}
