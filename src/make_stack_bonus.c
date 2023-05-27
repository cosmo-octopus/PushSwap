/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:21:58 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/27 20:00:21 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*curr;

	if (!new_node || !lst)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	curr = ft_lstlast(*lst);
	curr->next = new_node;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*fill_list(t_list *a, int *arr, int arg_count)
{
	t_list	*head;
	int		index;

	head = a;
	while (a)
	{
		index = find_index(arr, a->value, arg_count);
		a->index = index;
		a = a->next;
	}
	return (head);
}

t_list	*make_node(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	free_stack(t_list **head)
{
	t_list	*temp;

	if (head)
	{
		while (*head)
		{
			temp = *head;
			*head = (*head)->next;
			free(temp);
		}
	}
}
