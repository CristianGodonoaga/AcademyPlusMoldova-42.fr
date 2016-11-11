#include "libft.h"

t_list      *ft_lstnew(void const *content, size_t content_size)
{
    t_list      *temp;

    temp = (t_list*)malloc(sizeof(t_list));
    if(!temp)
        return (NULL);
    temp->content = (void*)content;
    temp->next = NULL;
    (!content)?(temp->content_size = 0):(temp->content_size = content_size);
    return (temp);
}
