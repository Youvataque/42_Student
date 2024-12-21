/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:46:45 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 17:20:45 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for init the list.
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
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		b = NULL;
		if (ft_lstsize(a) == 2)
			sort_two(a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			quartile_sort(&a, &b);
	}
	else
		return (1);
	return (0);
}
