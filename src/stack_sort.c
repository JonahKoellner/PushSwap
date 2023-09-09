/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:57:46 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/05/30 11:19:52 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

/**
 * Calculates the shoretes amount and sets it
 * Returns the length of both rotations combined
*/
int	shorten(t_instruct *ins, t_stack *s_a, t_stack *s_b)
{
	if (ins[1].rot > s_b->holds / 2)
		ins[1] = (t_instruct){.op = (void (*)(void *, void *)) & rr,
			.rot = s_b->length - (ins[1].rot + (s_b->length - s_b->holds))};
	if (ins[0].rot > s_a->holds / 2)
		ins[0] = (t_instruct){.op = (void (*)(void *, void *)) & rr,
			.rot = s_a->length - (ins[0].rot + (s_a->length - s_a->holds))};
	return (ins[0].rot + ins[1].rot + ins[2].rot);
}

int	cheap(t_stack *s_a, t_stack *s_b, int index, t_instruct *ch)
{
	t_instruct	*cur;

	cur = ft_calloc(3, sizeof(t_instruct));
	while (index < s_a->length)
	{
		cur[0] = (t_instruct){.op = (void (*)(void *, void *)) & r,
			.rot = index - (s_a->length - s_a->holds)};
		cur[1] = (t_instruct){.op = (void (*)(void *, void *)) & r,
			.rot = fns(s_b, s_a->data[index]) - (s_b->length - s_b->holds)};
		if (ch[0].rot == -1
			|| ch[0].rot + ch[1].rot + ch[2].rot > shorten(cur, s_a, s_b))
		{
			ch[0] = cur[0];
			ch[1] = cur[1];
			ch[2] = cur[2];
		}
		index++;
	}
	free(cur);
	return (0);
}

int	shift_back(t_stack *s_a, t_stack *s_b)
{
	t_instruct	away;
	int			ideal;

	while (s_b->holds)
	{
		ideal = fnb(s_a, s_b->data[s_b->length - s_b->holds]);
		if (s_b->data[s_b->length - s_b->holds] > s_a->data[find_max(s_a)])
			ideal = find_smallest(s_a);
		if (ideal == s_a->length - s_a->holds)
			p(s_a, s_b, 0);
		else
		{
			away = (t_instruct){.rot = ideal - (s_a->length - s_a->holds),
				.op = (void (*)(void *, void *)) & r};
			if (away.rot > s_a->holds / 2)
				away = (t_instruct){.rot = s_a->holds - away.rot,
					.op = (void (*)(void *, void *)) & rr};
			while (away.rot-- > 0)
				away.op(s_a, 0);
			p(s_a, s_b, 0);
		}
	}
	return (0);
}

int	rotate_finish(t_stack *s_a)
{
	while (find_max(s_a) != s_a->length - 1)
	{
		if (find_max(s_a) > s_a->holds / 2)
			rr(s_a, 0);
		else
			r(s_a, 0);
	}
	return (0);
}

int	sort_stack(t_stack *s_a, t_stack *s_b)
{
	t_instruct	*ch;
	int			index;

	while (s_a->holds > 3)
	{
		index = s_a->length - s_a->holds;
		ch = ft_calloc(3, sizeof(t_instruct));
		ch[0].rot = -1;
		cheap(s_a, s_b, index, ch);
		while (ch[2].rot-- > 0)
			ch[2].op(s_a, s_b);
		while (ch[0].rot-- > 0)
			ch[0].op(s_a, 0);
		while (ch[1].rot-- > 0)
			ch[1].op(s_b, 0);
		p(s_a, s_b, 1);
		free(ch);
	}
	case_algorithm(s_a, s_a->length - s_a->holds);
	shift_back(s_a, s_b);
	rotate_finish(s_a);
	return (0);
}
