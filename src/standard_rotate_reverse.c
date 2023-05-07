/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_rotate_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:57 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:58 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_list **head, char c)
{
	t_list	*first;
	t_list	*tmp;

	if (!head || !(*head) || !(*head)->next)
		return (-1);
	first = *head;
	tmp = (*head)->next;
	(*head)->next = NULL;
	*head = tmp;
	tmp = ft_lstlast(tmp);
	tmp->next = first;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == '0')
		return (0);
	return (0);
}

int	rotate_stacks(t_list **a, t_list **b)
{
	rotate(a, '0');
	rotate(b, '0');
	return (0);
}

int	reverse_rotate(t_list **head, char c)
{
	t_list	*first;
	t_list	*new_last;

	if (!head || !(*head) || !(*head)->next)
		return (-1);
	first = *head;
	while ((*head)->next->next)
		*head = (*head)->next;
	new_last = *head;
	*head = (*head)->next;
	new_last->next = NULL;
	(*head)->next = first;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else if (c == '0')
		return (0);
	return (0);
}

int	reverse_rotate_stacks(t_list **a, t_list **b)
{
	reverse_rotate(a, '0');
	reverse_rotate(b, '0');
	return (0);
}
