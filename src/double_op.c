/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:23:25 by jkollner          #+#    #+#             */
/*   Updated: 2023/06/01 09:54:32 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

int	whites(char c)
{
	return (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ');
}

long long	long_atoi(const char *str)
{
	long long	ret_val;
	int			prefix;
	int			counter;

	counter = 0;
	prefix = 1;
	ret_val = 0;
	while (whites(str[counter]))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			prefix *= -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		ret_val *= 10;
		ret_val += str[counter] - '0';
		counter++;
	}
	return (prefix * ret_val);
}

void	rrr(t_stack *a, t_stack *b)
{
	rr(a, 1);
	rr(b, 1);
	ft_printf("rrr\n");
}

void	tr(t_stack *a, t_stack *b)
{
	r(a, 1);
	r(b, 1);
	ft_printf("rr\n");
}
