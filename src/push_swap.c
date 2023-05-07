/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:15 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:25 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_args(char **argv)
{
	int	i;
	int	arg_count;
	int	curr_arg_count;

	i = 1;
	arg_count = 0;
	curr_arg_count = 0;
	while (argv[i])
	{
		curr_arg_count = check_arg(argv[i++]);
		if (curr_arg_count == -1)
		{
			ft_error();
			exit(1);
		}
		else
			arg_count += curr_arg_count;
	}
	return (arg_count);
}

void	go_sort(t_list **a, t_list **b, int arg_count)
{
	if (arg_count == 2)
		sort_for_two(a);
	else if (arg_count <= 3)
		sort_for_three(a, arg_count);
	else if (arg_count > 3 && arg_count <= 12)
		sort_for_twelve(a, b, arg_count);
	else
	{
		scan_stack_a(a, b, arg_count);
		find_max_b(a, b, arg_count);
	}
}

int	arg_check(int arg_count, char **argv)
{
	long	num;

	if (arg_count == 1)
	{
		num = atoi_long(argv[1]);
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		return (0);
	}
	return (0);
}

static void	exec_main(t_list *a, t_list *b, int arg_count, int *arr)
{
	quick_sort(arr, 0, arg_count - 1);
	a = fill_list(a, arr, arg_count);
	free(arr);
	go_sort(&a, &b, arg_count);
	free_stack(&a);
	free_stack(&b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		arg_count;
	int		*arr;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	arg_count = count_args(argv);
	if (arg_check(arg_count, argv) == -1)
		return (ft_error());
	arr = make_array(argv, arg_count);
	if (check_if_sorted(arr, arg_count) == -1)
		return (0);
	if (twin_check(arr, arg_count) == 0)
		return (ft_error());
	i = 0;
	while (i < arg_count)
		ft_lstadd_back(&a, make_node(arr[i++]));
	exec_main(a, b, arg_count, arr);
}
