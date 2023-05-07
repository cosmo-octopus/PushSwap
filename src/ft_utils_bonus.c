/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:21:15 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/07 16:21:18 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arg_count2(char **argv, int argc)
{
	int	i;
	int	arg_count;
	int	curr_arg_count;

	if (argc == 1)
		return (0);
	i = 1;
	arg_count = 0;
	curr_arg_count = 0;
	while (argv[i])
	{
		curr_arg_count = check_arg(argv[i++]);
		if (curr_arg_count == -1)
		{
			ft_error();
			return (-1);
		}
		else
			arg_count += curr_arg_count;
	}
	return (arg_count);
}

int	is_sorted(t_list **a)
{
	t_list	*tmp;
	int		a_len;

	tmp = *a;
	a_len = 1;
	while (tmp && tmp->next)
	{
		if (tmp->value > (tmp->next)->value)
			return (0);
		tmp = tmp->next;
		a_len += 1;
	}
	return (a_len);
}

void	do_command(t_list **a, t_list **b, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'p' && line[i + 1] == 'a')
		push(b, a, '0');
	else if (line[i] == 'p' && line[i + 1] == 'b')
		push(a, b, '0');
	else if (line[i] == 's' && line[i + 1] == 'a')
		swap(a, '0');
	else if (line[i] == 's' && line[i + 1] == 'b')
		swap(b, '0');
	else if (line[i] == 'r' && line[i + 1] == 'a')
		rotate(a, '0');
	else if (line[i] == 'r' && line[i + 1] == 'b')
		rotate(b, '0');
	else if (line[i] == 'r' && line[i + 1] == 'r' && line[i + 2] == 'a')
		reverse_rotate(a, '0');
	else if (line[i] == 'r' && line[i + 1] == 'r' && line[i + 2] == 'b')
		reverse_rotate(b, '0');
	else if (line[i] == 'r' && line[i + 1] == 'r' && line[i + 2] == 'r')
		reverse_rotate_stacks(a, b);
	else if (line[i] == 'r' && line[i + 1] == 'r')
		rotate_stacks(a, b);
	else if (line[i] == 's' && line[i + 1] == 's')
		swap_stacks(a, b);
}

int	input_valid(char *line)
{
	if (line[0] == 'p' && line[1] == 'a')
		return (1);
	else if (line[0] == 'p' && line[1] == 'b')
		return (1);
	else if (line[0] == 's' && line[1] == 'a')
		return (1);
	else if (line[0] == 's' && line[1] == 'b')
		return (1);
	else if (line[0] == 'r' && line[1] == 'a')
		return (1);
	else if (line[0] == 'r' && line[1] == 'b')
		return (1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		return (1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		return (1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		return (1);
	else if (line[0] == 'r' && line[1] == 'r')
		return (1);
	else if (line[0] == 's' && line[1] == 's')
		return (1);
	return (0);
}

void	get_command(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return ;
		if (!input_valid(line))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		do_command(a, b, line);
		free(line);
	}
}
