/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:48:02 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/09 09:30:22 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// push first element of "from" to "to"
void	push_in(t_list **to, t_list **from)
{
	t_list	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = NULL;
	if (*to == NULL)
		*to = temp;
	else
		ft_lstadd_front(to, temp);
}

///////////////////////////////////////////////////////////////////////////////
// pa instruction, push one element from b to a
void	pa(t_list **a, t_list **b)
{
	push_in(a, b);
	ft_putstr_fd("pa\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// pb instruction, push one element from a to b
void	pb(t_list **a, t_list **b)
{
	push_in(b, a);
	ft_putstr_fd("pb\n", 1);
}
