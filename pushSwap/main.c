/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:46:45 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/15 16:26:47 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for init a node of the list from list_str
t_list	*create_node_from_str(char *str, t_list **lst)
{
	void	*val;
	char	*temp;
	int		j;

	j = end_word_index(str);
	temp = ft_strndup(str, j);
	if (converted_val(temp, &val) && (!lst || !ft_lstcontain(*lst, val)))
	{
		free(temp);
		return (ft_lstnew(val));
	}
	free(temp);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////
// function for init a list from a str. "1 2   4 67"
t_list	*init_list_str(char *str)
{
	t_list	*lst;
	t_list	*new_node;
	int		i;

	lst = NULL;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		new_node = create_node_from_str(&str[i], &lst);
		if (!new_node)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (lst);
}

///////////////////////////////////////////////////////////////////////////////
// function for init the list from a pointer of str. ["1", "2", "4", "67"]
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

void	execute(t_list **a, t_list **b)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
		sort_two(*a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 5)
		five_sort(a, b);
	else
		quartile_sort(a, b);
}

///////////////////////////////////////////////////////////////////////////////
// main function
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		if (argc == 2)
			a = init_list_str(argv[1]);
		else
			a = init_list(argc, argv);
		if (a == NULL)
			return (ft_putstr_fd("Error\n", 1), 1);
		b = NULL;
		execute(&a, &b);
		ft_lstclear(&a, free);
	}
	else
		return (1);
	return (0);
}
