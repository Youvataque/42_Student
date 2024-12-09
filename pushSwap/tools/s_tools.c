/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:49:05 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/09 12:56:59 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for swap two first integer
int	swap(t_list *lst)
{
	void	*temp;

	if (ft_lstsize(lst) > 1)
	{
		temp = lst->next->content;
		lst->next->content = lst->content;
		lst->content = temp;
		return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// instruction sa swap two int for pile for a
void	sa(t_list *a)
{
	if (swap(a))
		ft_putstr_fd("sa\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction sb swap two int for pile b
void	sb(t_list *b)
{
	if (swap(b))
		ft_putstr_fd("sb\n", 1);
}

///////////////////////////////////////////////////////////////////////////////
// instruction ss swap two int of a and b
void	ss(t_list *b, t_list *a)
{
	if (swap(b) && swap(a))
		ft_putstr_fd("ss\n", 1);
}
