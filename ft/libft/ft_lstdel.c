#include "libft.h"

void        ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list      *ptr_next;
    t_list      *ptr_curent;

    ptr_next = (*alst)->next;
    ptr_curent = *alst;
    while (ptr_curent)
    {
        ft_lstdelone(&ptr_curent,del);
        ptr_curent = ptr_next;
        ptr_next = ptr_curent->next;
    }
    *alst = NULL;
}
