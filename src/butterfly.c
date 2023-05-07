/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:18:29 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:18:33 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	scan_stack_a(t_list **a, t_list **b, int a_size)
{
	int	r;
	int	i;

	i = 0;
	r = ft_sqrt(a_size) + log_two(a_size) - 1;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			i++;
		}
		else if ((*a)->index <= i + r)
		{
			push(a, b, 'b');
			i++;
		}
		else
			rotate(a, 'a');
	}
}

void	make_it_first_a(t_list **a, t_list *curr, int *arg_count, int *counter)
{
	while ((*a)->value != curr->value)
	{
		if ((*counter) >= (*arg_count) / 2)
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
	}
	(*arg_count)--;
	*counter = 0;
}

void	make_it_first_b(t_list **b, t_list *curr, int *arg_count, int *counter)
{
	while ((*b)->value != curr->value)
	{
		if ((*counter) >= (*arg_count) / 2)
			reverse_rotate(b, 'b');
		else
			rotate(b, 'b');
	}
	(*arg_count)--;
	*counter = 0;
}

void	find_max_b(t_list **a, t_list **b, int arg_count)
{
	int		counter;
	t_list	*curr;

	curr = *b;
	counter = 0;
	while (curr)
	{
		if (curr->index == arg_count - 1)
		{
			make_it_first_b(b, curr, &arg_count, &counter);
			push(b, a, 'a');
			curr = *b;
		}
		else
		{
			curr = curr->next;
			counter++;
		}
	}
}
