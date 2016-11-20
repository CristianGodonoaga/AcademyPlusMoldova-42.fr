#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	result = f(lst);
	temp = result;
	while (lst->next)
	{
		lst = lst->next;
		if (!temp)
			return (NULL);
		temp->next = f(lst);
		temp = temp->next;
	}
	return (result);
}
