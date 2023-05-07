/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:39 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:41 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_for_two(t_list **head)
{
	swap(head, 'a');
}

void	sort_for_three(t_list **head, int arg_count)
{
	if ((*head)->index < (*head)->next->index
		&& (*head)->next->index < (*head)->next->next->index)
		return ;
	if ((*head)->index == arg_count - 1)
	{
		rotate(head, 'a');
		if ((*head)->index == arg_count - 2)
			swap(head, 'a');
	}
	else if ((*head)->index == arg_count - 3
		&& (*head)->next->index != arg_count - 2)
	{
		reverse_rotate(head, 'a');
		swap(head, 'a');
	}
	else if ((*head)->index == arg_count - 2)
	{
		if ((*head)->next->index == arg_count - 1)
			reverse_rotate(head, 'a');
		else
			swap(head, 'a');
	}
}

void	sort_for_twelve(t_list **a, t_list **b, int arg_count)
{
	t_list	*curr;
	int		idx;
	int		counter;
	int		save_arg_count;

	curr = *a;
	idx = 0;
	counter = 0;
	save_arg_count = arg_count;
	while (arg_count > 3)
	{
		if (curr->index == idx)
		{
			make_it_first_a(a, curr, &arg_count, &counter);
			push(a, b, 'b');
			idx++;
			curr = *a;
			continue ;
		}
		curr = curr->next;
		counter++;
	}
	sort_for_three(a, save_arg_count);
	while (*b)
		push(b, a, 'a');
}
