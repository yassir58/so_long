#include "solong.h"


char **extract_map(void)
{
    int i;
    char *line;
    char **map;

    line = NULL;
    i = 0;
    map = (char  **)malloc(1000 * sizeof(char *));
    if (!map)
        return (NULL);
    int fd = open("test.ber", O_RDONLY);
    while ((line = get_next_line(fd)))
        map[i++] = line;
    map[i] = NULL;
    return (map);
}


void process_map(char **map, int *ln, int *en)
{
    int line_number = 0;
    int elem_number = 0;

    if (map)
    {
        while (map[line_number])
        {
            printf ("|%s|\n",map[line_number]);
            line_number++;
        }
        *ln = line_number;
        *en = ft_strlen(map[0]) - 1;
    }
}
/*
int check_for_valid_map(char **map)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (map[i])
    {
        k = ft_strlen(map[i]);
        if ((map[i][0] == '1' && map[i][k - 1] == '1'))
            return (0);
            i++;
    }
    while (map[0][j]])
    {
        if (map[0][j] != '1')
            return (0);
        j++;
    }
    j = 0;
    --i;
    while (map[i][j])
    {
         if (map[0][j] != '1')
            return (0);
        j++;
    }

    

}*/


void draw_map(t_data *data)
{
    int x=0, y=0, i=0, j=0;
   
    while (data->map_tab[i])
    {
        while (data->map_tab[i][j])
        {
           display_image(data, i, j, x, y);
            x += ELM_WIDTH;
            j++;
        }
        y += ELM_WIDTH;
        j = 0;
        x = 0;
        i++;
    }
}


void get_element_position(char **map, int *i, int *j, char c)
{
    int in = 0;
    int jn = 0;
    while (map[in])
    {
         
        while (map[in][jn])
        {
            if (map[in][jn] == c)
            {
                *i = in;
                *j = jn;
            }
           jn++;
        }
        jn = 0;
        in++;
    }
}


int coin_count(char **map)
{
    int i = 0;
    int j = 0;
    int coin_count = 0;

    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                coin_count++;

            j++;
        }
        j = 0;
        i++;
    }
    return (coin_count);
}


void end_game(t_data *data)
{
    int player_p_row = 0;
    int player_p_column = 0;
    int door_p_row = 0;
    int door_p_column = 0;
    get_element_position(data->map_tab, &player_p_row, &player_p_column, 'P');
    get_element_position(data->map_tab, &door_p_row, &door_p_column, 'E');
    data->map_tab[player_p_row][player_p_column] = '0';
    data->map_tab[door_p_row][door_p_column] = 'O';
    data->map.game_over = TRUE;
}