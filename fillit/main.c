#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


t_list      *ft_figure_extract(char *string);

t_piece *get_figure(char buf[]);

t_piece     *get_coordinates(t_piece *temp, char buf[]);

int         main(int argc, char **argv)
{
    int     fd;
    t_list  *figure;
    argc = 2;
    if(argc != 2)
    {
        ft_putstr("number of parameter is invalid");
        return (0);
    }
    if(!(figure = ft_figure_extract("test")))
    {
        ft_putstr("error");
        return (0);
    }

    return (0);
}
/*
**
**
**
*/
t_list      *ft_figure_extract(char *f_name)
{
    int     fd;
    char    buf[BUFSIZ + 1];
    int     length;
    char    letter;
    t_list  *list_head;
    t_piece *temp;

    temp = NULL;
    letter = 'A';
    if((fd = open(f_name, O_RDONLY | O_CREAT)) == -1)
    {
        ft_putstr(strerror(errno));
        return (NULL);
    }
    while((length = (int)read(fd, buf, 21)) >= 20)
    {
        if(!(length == 21 && buf[20] != '\n') && (temp = get_figure(buf)))
        {
            temp->letter = letter++;
            ft_lstadd(&list_head, ft_lstnew(temp, sizeof(*temp)));
            free(temp);
        }
        else
        {
            //ft_lstdel();
            close(fd);
            return NULL;//error
        }
    }
    close(fd);
    return NULL;
}
/*
**
*/
t_piece     *get_figure(char buf[])
{
    t_piece *temp;
    int     i;

    temp = (t_piece*)malloc(sizeof(*temp));
    if (!temp)
        return (NULL);
    temp = get_coordinates(temp, buf);
    return temp;
}
/*
**Check and validate the tetriminos figure
*/
t_piece*     get_coordinates(t_piece *temp, char buf[])
{
    short   i;
    short   j;

    i = 0;
    j = 0;
    int g = 0;
    while ((buf[i] == '#' || buf[i] == '.' || buf[i] == 1) ||
            (!(i % 5 < 4) && buf[i] == '\n') && i < 20)
    {
        if ((buf[i] == '#' && !j) || buf[i] == 1)
        {
            temp->coordinates[j][0] = (short)((i + 1) / 5);
            temp->coordinates[j][1] = (short)(i - ((i + 1) / 5) * 5);
            if (((i + 1) % 5) && buf[i + 1] == '#')
                buf[i + 1] = 1;
            if ((i + 5 < 20) && buf[i + 5] == '#')
                buf[i + 5] = 1;
            j++;
        }
        i++;
    }
    if(j == 4)
        return (temp);
    return (NULL);
}

/*
int		check_counts(char *str, int count)
{
    int i;
    int blocs;

    blocs = 0;
    i = 0;
    while (i < 20)
    {
        if (i % 5 < 4)
        {
            if (!(str[i] == '#' || str[i] == '.'))
                return (1);
            if (str[i] == '#' && ++blocs > 4)
                return (2);
        }
        else if (str[i] != '\n')
            return (3);
        i++;
    }
    if (count == 21 && str[20] != '\n')
        return (4);
    if (!check_connection(str))
        return (5);
    return (0);
}
*/
