#include "solong.h"

int duplicate(char **map, char c)
{
    int i ;
    int j ;
    int count;

    i = 0;
    j = 0;
    count  = 0;
    while (map[i])
    {
        while(map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] == c)
                count++;           
            j++;
        }
        j = 0;
        i++;
    }
    if (count > 1)
        return (1);
    return (0);
}

int check_for_valid_file(char *str)
{
    int len;
    int i;
    char *ext;
    int ext_len;

    i = 0;
    len = 0;
    ext = ".ber";
    ext_len = 4;
    len = ft_strlen(str) - 1;
   while (ext_len--)
   {
       if (str[len - i++] != ext[ext_len])
        return (0);
   }
   return (1);
}