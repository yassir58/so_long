#include "solong.h"


char **extract_map(void)
{
    int i = 0;
    char *line = NULL;
    char **map;

    map = (char  **)malloc(1000 * sizeof(char *));
    if (!map)
    {
        printf ("run out of heap memory\n");
        return (NULL);
    }
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

/*int check_for_valid_map(char **map)
{
    int i = 0;
    int j = 0;

    

}*/


void draw_map(t_data *data)
{
    int x=0, y=0, i=0, j=0;
    t_img wall;
    t_img monster;
    t_img coin;
    t_img empty_space;
    t_img closed_door;
    t_img open_door;
    
    init_images(&monster, &empty_space, &coin, data);
    init_images_(&wall, &closed_door, &open_door, data);
    while (data->map_tab[i])
    {
        while (data->map_tab[i][j])
        {
            if (data->map_tab[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, wall.mlx_img,x,y);
            else if (data->map_tab[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win,empty_space.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win,coin.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win,monster.mlx_img,x, y);
            else if (data->map_tab[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win,closed_door.mlx_img,x,y);
            else if (data->map_tab[i][j] == 'O')
                 mlx_put_image_to_window(data->mlx, data->win,open_door.mlx_img,x,y);

            x += ELM_WIDTH;
            j++;
        }
        y += ELM_WIDTH;
        j= 0;
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
    data->map.end_game = TRUE;
}