/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:07 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 13:07:24 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

# include "libft/libft.h"

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
int		converted_val(char *n, void **result);
int		ft_lstcontain(t_list *lst, void *content);
int		is_sorted(t_list *lst);
int		*min_max(t_list *lst);
int		search_inter(t_list *a, int target, int max, int *index);
void	quick_sort(int array[], int low, int high);
void	set_quartils(t_list *a, t_quarts *quarts);
void	push_good_b(t_list **a, t_list **b);
void	sort_three(t_list **a);

/* sorts */
void	sort_two(t_list *a);
void	selection(t_list **a, t_list **b);
void	monotone_sort(t_list **a, t_list **b);
void	quartile_sort(t_list **a, t_list **b);

#endif