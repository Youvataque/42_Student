/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:46:45 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/11 21:13:09 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for init the list.
t_list	*init_list(int argc, char **argv)
{
	t_list	*lst;
	void	*val;
	int		i;

	if (converted_val(argv[1], &val))
	{
		lst = ft_lstnew(val);
		i = 2;
		while (i < argc)
		{
			if (converted_val(argv[i], &val) && !ft_lstcontain(lst, val))
				ft_lstadd_back(&lst, ft_lstnew(val));
			else
			{
				ft_lstclear(&lst, free);
				return (NULL);
			}
			i++;
		}
		return (lst);
	}
	else
		return (NULL);
}

void	sort_test(t_list **b)
{
	while (1)
	{
		sb(*b);
		if (is_sorted(*b))
			break ;
		rb(b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		a = init_list(argc, argv);
		if (a == NULL)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		b = NULL;
		if (ft_lstsize(a) == 2)
			sort_two(a);
		else
			monotone_sort(&a, &b);
		while (a)
		{
			ft_printf("val : %d\n", *(int *)a->content);
			a = a->next;
		}
	}
	else
		return (1);
	return (0);
}
