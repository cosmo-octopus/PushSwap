/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:23:27 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/22 20:07:50 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

//_______________________/split + utils/____________________________//
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_free(char **str);
//__________________________________________________________________//
void	free_stack(t_list **head);
long	atoi_long(const char *str);
int		check_arg(char *arg);
int		count_args(char **argv);
void	go_sort(t_list **a, t_list **b, int arg_count);
int		ft_error(void);
t_list	*make_node(int value);
int		*make_array(char **arg, int size);
void	make_it_first_a(t_list **a, t_list *curr, int *arg_count, int *counter);
void	make_it_first_b(t_list **b, t_list *curr, int *arg_count, int *counter);
int		twin_check(int *arr, int size);
void	quick_sort(int	*arr, int low, int high);
void	quick_recursion(int *arr, int low, int high, int i);
int		find_index(int *arr, int value, int arg_count);
t_list	*fill_list(t_list *a, int *arr, int arg_count);
int		swap(t_list **stack, char c);
int		push(t_list **source, t_list **dest, char c);
int		rotate(t_list **head, char c);
int		rotate_stacks(t_list **a, t_list **b);
int		reverse_rotate(t_list **head, char c);
int		reverse_rotate_stacks(t_list **a, t_list **b);
int		swap_stacks(t_list **stack_a, t_list **stack_b);
int		ft_sqrt(int num);
int		log_two(int nb);
void	scan_stack_a(t_list **a, t_list **b, int a_size);
void	find_max_b(t_list **a, t_list **b, int arg_count);
int		check_if_sorted(int *arr, int arg_count);
void	sort_for_two(t_list **head);
void	sort_for_three(t_list **head, int arg_count);
void	sort_for_twelve(t_list **a, t_list **b, int arg_count);

#endif
