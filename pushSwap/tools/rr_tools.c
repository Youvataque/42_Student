/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:15:18 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 16:08:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	r_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	second_last = *lst;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rerverse rotate a
void	rra(t_list **a)
{
	r_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rerverse rotate b
void	rrb(t_list **b)
{
	r_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rerverse rotate a and b
void	rrr(t_list **a, t_list **b)
{
	r_rotate(b);
	r_rotate(a);
	ft_putstr_fd("rrr\n", 1);
}
