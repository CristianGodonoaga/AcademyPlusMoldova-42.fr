#include "../includes/libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*tList_figures;

	if(argc != 2)
	{
		ft_putstr("number of parameter is invalid");
		return (0);
	}
	if(!(tList_figures = ft_figure_extract(fd =
			open(argv[1], O_RDONLY | O_CREAT))))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	solve(tList_figures);
	return (0);
}

t_list		*ft_figure_extract(int fd)
{
	char	buf[BUFSIZ + 1];
	int		length;
	char	letter;
	t_list	*list_head;
	t_piece	*temp;
	char	mark;

	letter = 'A';
	mark = 0;
	list_head = NULL;
	while (((length = (int)read(fd, buf, 21)) >= 19) &&
			(temp = detect_figure(buf, length, letter++)))
	{
		mark = (length == 21);
		ft_lstadd(&list_head, ft_lstnew(temp, sizeof(*temp)));
		free(temp);
	}
	if (mark || length)
	{
		ft_lstfree(&list_head);
		return (NULL);
	}
	return (list_head);
}

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
**Check and validate the tetriminos figure
*/
t_piece			*detect_figure(char *buf, int length, char letter)
{
	t_piece		*temp;

	if (length == 21 && buf[20] != '\n')
		return (NULL);
	temp = (t_piece*)malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	if (!check_connection(buf) || !(temp = get_coordinates(temp, buf)))
	{
		free(temp);
		return (NULL);
	}
	temp->letter = letter;
	temp->coord[1][0] -= temp->coord[0][0];
	temp->coord[1][1] -= temp->coord[0][1];
	temp->coord[2][0] -= temp->coord[0][0];
	temp->coord[2][1] -= temp->coord[0][1];
	temp->coord[3][0] -= temp->coord[0][0];
	temp->coord[3][1] -= temp->coord[0][1];
	temp->coord[0][0] = 0;
	temp->coord[0][1] = 0;
	return (temp);
}

/*
**Get coordinates and validate figure
*/
t_piece*		get_coordinates(t_piece *temp, char buf[])
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	while ((buf[i] == '#' || buf[i] == '.') ||
			((!(i % 5 < 4) && buf[i] == '\n') && i < 20))
	{
		if (buf[i] == '#')
		{
			if (j > 3)
				return (NULL);
			temp->coord[j][0] = (short)((i + 1) / 5);
			temp->coord[j][1] = (short)(i - ((i + 1) / 5) * 5);
			j++;
		}
		i++;
	}
	if (j == 4)
		return (temp);
	return (NULL);
}
