#ifndef SWAPLIB_H

# include "libft/libft.h"

/* edit tools*/
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

/*other tools*/
int	converted_val(char *n, void **result);
int	ft_lstcontain(t_list *lst, void *content);

#endif