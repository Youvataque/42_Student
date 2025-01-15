/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:07 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/15 16:14:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

# include "libft/libft.h"
# include <limits.h>
/* struct of quartile sort */
typedef struct s_quarts
{
	double	q1;
	double	med;
	double	q2;
}	t_quarts;

/* edit tools */
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *b, t_list *a);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

/* other tools */
int		end_word_index(char *str);
int		get_index(t_list *lst, int target);
int		get_direction(int pos, t_list *lst);
int		converted_val(char *n, void **result);
int		ft_lstcontain(t_list *lst, void *content);
int		is_sorted(t_list *lst);
int		*min_max(t_list *lst);
void	set_quartils(t_list *a, t_quarts *quarts);

/* sorts utils */
int		search_inter(t_list *a, int target, int max);
int		search_best(t_list *a, t_list *b);
int		recup_a_pos(t_list *a, int b_pos);
void	push_good_b(t_list **a, t_list **b);

/* sorts */
void	five_sort(t_list **a, t_list **b);
void	quick_sort(int array[], int low, int high);
void	sort_two(t_list *a);
void	sort_three(t_list **a);
void	quartile_sort(t_list **a, t_list **b);

#endif