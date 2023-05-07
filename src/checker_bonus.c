/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:20:40 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:20:43 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	free_all(t_list *a, t_list *b, int *arr)
{
	free(arr);
	free_stack(&a);
	free_stack(&b);
}

void	final_check(t_list **a, t_list **b, int arg_count)
{
	int	a_len;

	if (*b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	a_len = is_sorted(a);
	if (a_len != arg_count)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		arg_count;
	int		*arr;

	a = NULL;
	b = NULL;
	arg_count = arg_count2(argv, argc);
	if (argc > 1)
	{
		if (arg_count == -1)
			return (1);
		arr = make_array(argv, arg_count);
		if (twin_check(arr, arg_count) == 0)
			return (ft_error());
		i = 0;
		while (i < arg_count)
			ft_lstadd_back(&a, make_node(arr[i++]));
		quick_sort(arr, 0, arg_count - 1);
		a = fill_list(a, arr, arg_count);
		get_command(&a, &b);
		final_check(&a, &b, arg_count);
		free_all(a, b, arr);
	}
}
