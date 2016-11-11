#include "libft.h"

void        ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    t_list      *ptr_next;
    t_list      *ptr_curent;

    ptr_next = lst->next;
    ptr_curent = lst;
    while (ptr_curent)
    {
        f(ptr_curent);
        ptr_curent = ptr_next;
        ptr_next = ptr_curent->next;
    }
}
