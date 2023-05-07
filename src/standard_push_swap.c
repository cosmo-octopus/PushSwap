/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:46 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:47 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **stack, char c)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (-1);
	if (*stack)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		first = second;
		*stack = first;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
		else if (c == '0')
			return (0);
		return (1);
	}
	return (0);
}

int	swap_stacks(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, '0');
	swap(stack_b, '0');
	return (0);
}

int	push(t_list **source, t_list **dest, char c)
{
	t_list	*tmp;

	if (!source || !(*source))
		return (-1);
	tmp = *source;
	*source = (*source)->next;
	tmp->next = NULL;
	if (*dest == NULL)
		*dest = tmp;
	else
	{
		tmp->next = *dest;
		*dest = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	else if (c == '0')
		return (0);
	return (0);
}
