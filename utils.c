#include "solong.h"

char read_ch(int fd)
{
    char c_h;
    int read_return ;

    read_return  = 0;
    read_return = read(fd, &c_h, BUFFER_SIZE);
    if (read_return == -1 || read_return == 0)
        return (0);
    return (c_h);
}



char *put_ch(char *str, char c)
{
    int len;
    char *new_str;
    int i = 0;

    if (!str)
        return (NULL);
    len =  ft_strlen(str);
    new_str = malloc((len + 2) + sizeof(char));

    while (len--)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i+1] = '\0';
    return (new_str);
}

char *get_next_line(int fd)
{
   static char *backup;
    char c_h;
    char *line ;

    line = NULL ;
     c_h = read_ch(fd);

    
    if (fd == - 1 || (c_h == '\0' && !backup))
        return (NULL);
    if (c_h == '\n')
    {
       
        if (!backup)
        backup = ft_strdup("");
        line  = put_ch(backup, c_h);
         free(backup);
         free(line);
         backup = NULL ;
    }
    else
    {
        while (c_h != '\n' && c_h)
        {
            if (!backup)
                backup = ft_strdup("");
            backup = put_ch(backup, c_h);
            c_h = read_ch(fd);
        }
         line  = put_ch(backup, c_h);
         free(backup);
         free(line);
         backup = NULL ;
    }
    return (line);
}