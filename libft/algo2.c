// #include "push_swap.h"

// void	push_to_a(list_t **stack_a, list_t **stack_b)
// {
// 	int	len_b;
// 	int	p;

// 	if (!stack_a || !stack_b|| !*stack_b)
// 		return ;
// 	len_b = lst_size(*stack_b);
// 	while (len_b > 0)
// 	{
// 		p = max_ind(stack_b);
// 		if (p <= len_b / 2)
// 		{
// 			while (p-- > 0)
// 				rb(stack_b);
// 		}
// 		else
// 		{
// 			while (p++ < len_b)
// 				rrb(stack_b);
// 		}
// 		pa(stack_a, stack_b);
// 		len_b--;
// 	}
// }
