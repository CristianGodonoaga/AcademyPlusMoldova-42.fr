#include <stdlib>

typedef struct	list_s
{
	char		str[10];
	short		length;
	struct		list_s* ptr_to_next;
}				list_t;

typedef struct	list_extend_s
{
	char		str[10];
	short		length;
	struct		list_s* ptr_to_next;
	int			nbr_of_obj;
}				list_extend_t;

int		create_oneline(list_t* head_list, char** line)
{
	list_t* curent;

	curent
	while()
	{

	}
}

int		add_char_onlist(list_t** head, list_t** obj, char c)
{
	if (!*head)
	{
		if (!*head = (list_t*)malloc(sizeof(list_extend_t)))
			return (-1);
		(*(*list_extend_s)head)->nbr_of_obj = 0;
		(*head)->length = 0;
		(*head)->ptr_to_next = NULL;
		*obj = *head;
	}
	if ((*obj)->length == 10)
	{
		if (!(*obj)->ptr_to_next = (list_t*)malloc(sizeof(list_t)))
			return (-1);
		((*obj)->ptr_to_next)->length = 0;
		((*obj)->ptr_to_next)->ptr_to_next = NULL;
		return (add_char_onlist(head, obj, c));
	}
	(*head(*list_extend_s))->nbr_of_obj++;
	(*obj)->str[length] = c;
	(*obj)->length++;
	return (1);
}

int		get_next_line(int const fd, char** line)
{
	list_t*	head_list;
	list_t*	current_obj;
	char	buff[1];
	int		length;

	head_list = NULL;
	current_obj = NULL;
	while (legth = read(fd, buff, 1)) > 0)
		if (!add_char_onlist(&head_list, &current_obj, buff[1]))
		{
			dellete_list(head_list);
			return (-1);
		}
	if (length == -1)
		{
		dellete_list();
		return (-1);
		}
	if(head_list == NULL)
		return (0);
	return(create_oneline(head_list, line));
}
