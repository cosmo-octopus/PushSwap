/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:29 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/22 19:18:44 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_recursion(int *arr, int low, int high, int i)
{
	if (low < high)
	{
		if (i > 0)
		{
			quick_sort(arr, low, i);
			quick_sort(arr, i + 1, high);
		}
		else
			quick_sort(arr, i + 1, high);
	}
}

void	quick_sort(int	*arr, int low, int high)
{
	int	pivot;
	int	j;
	int	i;

	pivot = arr[high];
	j = low;
	i = low - 1;
	while (j < high)
	{
		if (arr[j] <= pivot)
			swap_int(&arr[++i], &arr[j]);
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	quick_recursion(arr, low, high, i);
}
