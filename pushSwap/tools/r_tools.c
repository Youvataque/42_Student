/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:45:45 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/08 15:17:18 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for rotate a liste (1, 2, 3 -> 2, 3, 1)
void	rotate(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rotate a
void	ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rotate b
void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction for rotate a and b
void	rr(t_list **a, t_list **b)
{
	rotate(b);
	rotate(a);
	ft_putstr_fd("rr\n", 1);
}
